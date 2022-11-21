#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;


typedef struct LinkQueue {
	ElemType data;
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
bool EnQueueL(LinkQueue& Q,ElemType x) {
	LinkNode* s = new LinkNode;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

//入队操作(不带头结点）
bool EnQueueLN(LinkQueue& Q, ElemType x) {
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
bool DeQueueL(LinkQueue& Q, ElemType& x) {
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
bool DeQueueLN(LinkQueue& Q, ElemType& x) {
	if (Q.front == NULL) {
		return false;
	};
	LinkNode* p = Q.front;
	x = p->data;
	Q.front = p->next;
	if (Q.rear = Q.front) {
		Q.front = NULL;
		Q.rear = NULL;
	};
	delete p;
	return true;
}


