#include<stdio.h>
#include<stdlib.h>



typedef int ElemType;



#define MaxSize 10

typedef struct Node {
	ElemType data;
	int next;
}DNode;

void main() {
	Node a[MaxSize];
	printf("sizeA=%d\n", int(sizeof(a)));
}

