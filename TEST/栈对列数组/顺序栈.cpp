#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];					//静态数组存放栈中元素
	int Top;								//栈顶执政
}SqStack;



//typedef struct ShStack {
//	ElemType data[MaxSize];
//	int top0;
//	int top1;
//}ShStack;
//
//
//
//void InitStack(ShStack& S) {
//	S.top0 = -1;
//	S.top1 = MaxSize;
//}

void InitStack(SqStack &S) {
	S.Top = -1;								//初始化栈顶执政
}

bool Push(SqStack& s, ElemType x) {
	if (s.Top == MaxSize - 1) {
		return false;
	};
	s.Top = s.Top + 1;						//等价于 s.data[++s.Top]=x;
	s.data[s.Top] = x;
	return true;
}

bool Pop(SqStack& s,ElemType &x) {
	if (s.Top == -1) {
		return false;
	};
	x = s.data[s.Top];						//等价于x=s.data[s.top--];
	s.Top = s.Top - 1;
	return true;
}

bool GetTop(SqStack s, ElemType& x){
	if (s.Top == -1) {
		return false;
	};
	x = s.data[s.Top];
	return true;
}




	





void main() {
	SqStack S;
}

