#include<stdio.h>
#include<stdlib.h>



typedef int ElemType;



#define MaxSize 10

typedef struct Node {
	ElemType data;
	int next;
}DNode;

void testLinkList() {
	Node a[MaxSize];
	printf("size=%d\n",sizeof(a));
}

