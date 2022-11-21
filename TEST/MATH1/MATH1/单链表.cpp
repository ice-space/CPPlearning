#include<stdio.h>
#include<stdlib.h>

//定义基本类型
typedef int ElemType;

//定义一个单链表
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;						//LNode和*LinkList等价
											//但是LNode强调是一个结点
											//LinkList强调是一个链表

//struct LNode* p = (struct LNode*)malloc(sizeof(struct LNode));
//
//
//struct LNode* p = new  LNode;



//初始化单链表(不带头结点）
bool InitList(LinkList& L) {
	L = NULL;
	return true;
}

//初始化单链表（带头结点）
bool InitListH(LinkList& L) {
	L = new LNode;
	if (L == NULL) {
		return false;
	};
	L->next = NULL;
	return true;
}

//判断单链表是否为空
bool Empty(LinkList L) {							//判断是否为空
	if (L->next = NULL) {
		return true;
	}
	else {
		return false;
	};
	;
	//return(L->next ==NULL);
}

//单链表按位序插入（带头结点）
bool ListInsertH(LinkList &L,int i,ElemType e) {
	if (i < 1) {
		return false;
	};
	LNode* p;										//指针p指向当前扫描到的结点
	int j = 0;										//当前p指针指向第几个结点；
	p = L;											//L指向头结点，头结点是第0个结点（不存储数据）


	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	};


	LNode *s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//插入（不带头头节点）
bool ListInsert(LinkList& L, int i, ElemType e) {
	if (i < 1) {
		return false;
	};
	if (i == 1) {
		LNode* s = new LNode;					//申请一个新的链表空间
		s->data = e;							//将加入位置的执政数据导入S
		s->next = L;							//S指向头指针指向的结点
		L = s;									//将头指针指向S
	}
	LNode* p;
	int j = 1;
	p = L;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	};


	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}


//指定结点后插
bool InsertNextNode(LNode* p, ElemType e) {
	if (p == NULL) {
		return false;
	};
	LNode* s = new LNode;
	if (s == NULL) {
		return false;
	};
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//指定结点的前插
bool InsertPriorNode(LNode* p, ElemType e) {
	if (p == NULL) {
		return false;
	};
	LNode* s = new LNode;
	if (s == NULL) {
		return false;
	};
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}
 
//按位序删除
bool ListDelete(LinkList& L, int i, ElemType& e) {
	if (i < 1) {
		return false;
	};
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	};
	if (p == NULL) {
		return false;
	};
	if (p->next = NULL) {
		return false;
	};
	LNode* q = p->next;
	e = q->data;
	delete(q);
	return true;
}

//指定结点删除
bool DeleteNode(LNode* p) {
	if (p == NULL) {
		return false;
	};
	LNode* q = p->next;
	p->data = p->next->data;
	p->next = q->next;
	free(q);
	return true;
}
 

//单链表查找
//LNode* GetElem(LinkList L, int i){
//	int j = 1;
//	LNode* p = L->next;
//	if (i == 0) {
//		return L;
//	};
//	if (i < 1) {
//		return NULL;
//	};
//	while (p != NULL && j < i) {
//		p = p->next;
//		j++;
//	};
//}

//按位查找(带头结点）
LNode* GetElem(LinkList L, int i) {
	if (i < 0) {
		return NULL;
	};
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	};
	return p;
}

//按值查找
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;
	//从第1个结点开始查找数据域为e的结点
	while (p != NULL && p->data != e) {
		p = p->next;
	};
	return p;
}

//求表长
int Length(LinkList L) {
	int len = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	};
	return len;
}


//尾插法
LinkList List_Taillnsert(LinkList& L) {
	ElemType x;
	L = new LNode;
	LNode* s, * r = L;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = new LNode;
		s->data = x;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	};
	r->next = NULL;
	return L;
}



//头插法(链表的逆置）
LinkList List_HeadInsert(LinkList& L) {
	LNode* s;
	int x;
	L = new LNode;
	L->next = NULL;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	};
	return L;
}




void test() {
	LinkList L;
	//初始化一个空表
	InitList(L);
	//...

}