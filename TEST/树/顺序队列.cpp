#include<stdio.h>
#include<stdlib.h>


typedef int Elemtype;
#define MaxSize 10

typedef struct Queue {
	Elemtype data[MaxSize];
	int front, rear;
	//int size；
	//int tag;
}SqQueue;


void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}

bool QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		return false;
	}
	else {
		return true:

	};
}
//入队操作
bool EnQueue(SqQueue& Q,Elemtype x) {
	if ((Q.rear+1)%MaxSize == Q.front) {
		return false;
	}
	Q.data[Q.rear] = x;								
	Q.rear = (Q.rear + 1)%MaxSize;						//	形成类似循环的队列
	return true;
}

//出队操作
bool DeQueue(SqQueue& Q, Elemtype& x) {
	if (Q.rear == Q.front) {
		return false;
	};
	x = Q.data[Q.front];
	Q.front = (Q.front+1)% MaxSize;						//	形成类似循环的队列
}

//通过取余进行循环队列并用 Q.rear+1)%Maxsize==Q.front 作为判断是否队满的条件会牺牲掉一个存贮空间。
//队列元素个数=（rear+Maxsize-front)%MaxSize


