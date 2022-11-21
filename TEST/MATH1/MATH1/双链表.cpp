#include<stdio.h>
#include<stdlib.h>


typedef int Elemtype;

typedef struct DNode {
	Elemtype data;
	struct DNode* prior, * next;
}DNode,*DLinklist;

bool InitDLinkList(DLinklist& L) {
	L = new DNode;
	if (L == NULL) {
		return false;
	};
	L->prior = NULL;
	L->next = NULL;
	return true;
}

bool Empty(DLinklist L) {
	if (L->next == NULL) {
		return true;
	}
	else {
		return false;
	};
}

//双链表的插入
bool InsertNextDNode(DNode *p, DNode* s) {
	if (p == NULL || s == NULL) {
		return false;
	};
	s->next = p->next;
	if (p->next != NULL) {
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;
}

//双链表的删除
bool DeleteNextDNode(DNode* p) {
	if (p == NULL) {
		return false;
	};
	DNode* q = p->next;
	if (q == NULL) {
		return false;
	};
	p->next = q->next;
	if (q->next != NULL) {
		q->next->prior = p;
	};
	delete(q);
	return true;
}

void DestoryList(DLinklist& L) {
	while (L - next != NULL) {
		DeleteNextDNode(L);
	};
	delete(L);
	L = NULL;
}
//双链表的遍历
while (p != NULL) {
	p = p->next;
}

while (p != NULL) {
	p = p->prior;
}

while (p->prior = NULL) {
	p = p->prior;
}
void testDLinkList() {
	
	//定义一个双链表
	DLinklist L;
	//初始化双链表
	InitDLinkList(L);
	//。。。


}