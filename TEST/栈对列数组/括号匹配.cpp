#include<stdio.h>

typedef char  ElemType;
#define MaxSize 10

typedef struct SqStack {
	ElemType data[MaxSize];
	int Top;
}SqStack;

void InitStack(SqStack& S) {
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


bool Pop(SqStack& s, ElemType& x) {
	if (s.Top == -1) {
		return false;
	};
	x = s.data[s.Top];						//等价于x=s.data[s.top--];
	s.Top = s.Top - 1;
	return true;
}


bool StackEmpty(SqStack S) {
	if (S.Top = -1) {
		return true;
	}
	return false;


}


bool bracketCheck(char str[], int length) {
	SqStack S;
	InitStack(S);
	for (int i = 0; i <= length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {

			Push(S, str[i]);
		}
		else {
			if (StackEmpty(S)) {
				return false;
			}
			char topElem;
			Pop(S, topElem);
			if (str[i] == ')' && topElem != '(') {
				return false;
			}
			if (str[i] == ']' && topElem != '[') {
				return false;
			}
			if (str[i] == '}' && topElem != '{') {
				return false;
			}
		}


	}
	return StackEmpty(S);
}













bool bracketCheck(char str[], int length) {
	Sqstack S;
	InitStack(S);





}