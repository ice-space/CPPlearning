#include<stdio.h>
#include<stdlib.h>


typedef int Elemtype;

typedef struct DNode {
	Elemtype data;
	struct DNode * prior, * next;
}DNode,*DLinkList;

bool InitDlinkList(DLinkList& L) {
	L = new DNode;
	if (L == NULL) {
		return false;								//判断内存是否已经满了
	};
	L ->prior  = L;
	L->next = L;

}

bool Empty(DLinkList L) {
	if (L->next == L) {
		return true;
	}
	else {
		return false;
	};

}

bool InsertNextDNode(DNode* p, DNode* s) {
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
}




void testDLinkList() {
	DLinkList L;
	
	InitDlinkList(L);
}

