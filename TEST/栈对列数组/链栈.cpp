#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}*LiStack;


// 初始化链栈
bool InitListack(LiStack& LS) {
	LS = new LinkNode;
	if (LS->next == NULL) {
		return false;
	}
	LS->data = NULL;
	LS->next = NULL;
	return false;
}


bool InsertStack(LiStack&LS) {
	
}



