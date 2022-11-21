#include<stdio.h>
#include<stdlib.h>

struct ElemType {
	int value;
};


typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;									//tag为1时，指针指向线索；tag为0时指向其子结点；
}ThreadNode,* ThreadTree;


typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;								//tag为1时，指针指向线索；tag为0时指向其子结点；
}BiTNode, * BiTree;


//辅助全局变量，用于查找结点p的前驱
BiTNode* p;															//p指向目标结点
BiTNode* pre = NULL;												//指向当前访问结点的前驱
BiTNode* final = NULL;												//用于记录最终结果

ThreadNode* pThread;															//p指向目标结点
ThreadNode* preThread = NULL;												//指向当前访问结点的前驱
ThreadNode* finalThread = NULL;
//用都办法找中序前驱

void findpre(BiTree T) {
	if (T != NULL) {
		findpre(T->lchild);
		visit(T);
		findpre(T->rchild);
	}
}

//访问结点q
void visit(BiTNode* q) {
	if (q == p) {
		final = pre;
	}
	else {
		pre = q;
	}
};

void visitThread(ThreadNode* q) {
	if (q->lchild == NULL) {
		q->lchild = preThread;
		q->ltag = 1;
	}
	if (preThread != NULL && preThread->rchild == NULL) {
		preThread->rchild = q;
		preThread->rtag = 1;
	}
	preThread = q;
}


void InThread(ThreadTree T) {
	if (T != NULL) {
		InThread(T->lchild);
		visitThread(T);
		InThread(T->rchild);
	}
}


//中序线索化二叉树T
void CreateInThread(ThreadTree T) {
	preThread = NULL;
	if (T != NULL) {
		InThread(T);
		if (preThread->rchild == NULL) {
			preThread->rtag = 1;
		}
	}
}

//标记上一个结点
void PreThread(ThreadTree T) {
	if (T != NULL) {
		visitThread(T);
		if (T->ltag == 0) {
			PreThread(T->lchild);
		}
		PreThread(T->rchild);
	}
}

//找中序后继

//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode* Firstnode(ThreadNode* p) {
	while (p->ltag == 0) {
		p = p->lchild;
	}
}


//在中序线索二叉树中找到结点p的后继结点
ThreadNode* Nextnode(ThreadNode* p) {
	if (p->rtag == 0) {
		return Firstnode(p->rchild);
	}
	else {
		return p->rchild;
	}
}


//对于中序线索二叉树进行中序遍历（利用线索实现非递归算法）
void InOrder(ThreadNode* T) {
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p)) {
		visitThread(p);
	}
}


//找中序前驱

//找到以p为根的子树，最后一个被中序遍历的结点
ThreadNode* Lastnode(ThreadNode* p) {
	//循环找到最右下结点（不一定是叶结点）
	while (p->rtag == 0) {
		p = p->rchild;
	}
	return p;
}

//在中序线索二叉树中找到结点p的前驱结点
ThreadNode* Prenode(ThreadNode* p) {
	//左子树中最右下结点
	if (p->ltag == 0) {
		return Lastnode(p->lchild);
	}
	else {
		return p->lchild;
	}
}

//对于中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode* T) {
	for (ThreadNode* p = Lastnode(T); p != NULL; p = Prenode(p)) {
		visitThread(p);
	}
}



//找先序后继(代码自己实现）





//找先序前驱




//找后序线索二叉树的后序前驱











