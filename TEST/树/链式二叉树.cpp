#include<stdio.h>
#include<stdlib.h>

struct Elemtype {
	int value;
};

typedef struct BiTNode {
	Elemtype data;
	struct BiTNode* lchild, * rchild;

}BiTNode, * BiTree;

int main() {
	BiTree root = NULL;
	root = (BiTree)malloc(sizeof(BiTNode));

	InitBiTree(root);

	InterBiTNode(root, 2);

}



bool InitBiTree(BiTree& T) {
	T->data = { 1 };
	T->lchild = NULL;
	T->rchild = NULL;
}


bool InterBiTNode(BiTNode*& T, int x) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { x };
	p->lchild = NULL;
	p->rchild = NULL;
	T->lchild = NULL;
}



//二叉树的遍历

void visit(BiTree T) {
	printf("%d", T->data);
}

//先序遍历
void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);						//递归左边子树
		PreOrder(T->rchild);						//递归右边子树
	}
};

void InOrder(BiTree T){
	if (T != NULL) {
		InOrder(T->lchild);							//递归左边子树
		visit(T);									//访问根节点
		InOrder(T->rchild);							//递归右边子树
	}
}

void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}


int treeDepth(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	else {
		int l = treeDepth(T->lchild);
		int r = treeDepth(T->rchild);
		//树的深度等于MAX（左子树深度，右子树深度）+1
		return l > r ? l + 1 : r + 1;
	}
}

//层序遍历

void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueueL(Q, T);
	while (!IsEmptyQueue(Q)) {
		DeQueueL(Q, p);
		visit(p);
		if (p->lchild != NULL) {
			EnQueueL(Q, p->lchild);
		}
		if (p->rchild != NULL) {
			EnQueueL(Q, p->rchild);
		}
	}
}







//链式队列函数
typedef struct LinkQueue {
	BiTNode *data;
	struct LinkQueue* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


//初始化带头结点
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new LinkNode;
	Q.front->next = NULL;
}

//初始化不带结点
void InitQueueN(LinkQueue& Q) {
	Q.front = Q.rear = new LinkNode;
	Q.front = NULL;
	Q.rear = NULL;
}

bool IsEmptyQueue(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	};
}



//入队操作(带头结点）
bool EnQueueL(LinkQueue& Q, BiTNode*x) {
	LinkNode* s = new LinkNode;
	s->data = x->data;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

//入队操作(不带头结点）
bool EnQueueLN(LinkQueue& Q, BiTNode*x) {
	LinkNode* s = new LinkNode;
	s->data = x;
	if (Q.front->next = NULL) {
		Q.front->next = s;
		Q.rear = s;
	}
	else {
		Q.rear->next = s;
		Q.rear = s;
	};
}


//出队操作(带头结点）
bool DeQueueL(LinkQueue& Q, BiTNode*& x) {
	if (Q.front == NULL) {
		return false;
	};
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.front;
	};
	delete p;
	return true;
}

//出队（不带头结点）
bool DeQueueLN(LinkQueue& Q, BiTNode*& x) {
	if (Q.front == NULL) {
		return false;
	};
	LinkNode* p = Q.front;
	x->data = p->data;
	Q.front = p->next;
	if (Q.rear = Q.front) {
		Q.front = NULL;
		Q.rear = NULL;
	};
	delete p;
	return true;
}