#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 255

typedef struct SString {					//静态数组实现串
	char ch[MAXLEN];
	int length;
}SString;

typedef struct HString{
	char* ch;
	int length;
}HString;

//初始化
void InitHString() {
	HString S;
	 S.ch = (char*)malloc(MAXLEN *sizeof(char));
	 S.length = 0;
}
//每个节点存1个结点
typedef struct StringNode {
	char ch;
	struct StringNode* next;
}StringNode,*String;


//每个结点多个结点
typedef struct StringNode {
	char ch[4];
	struct StringNode* next;
}StringNode, * String;

//求子串
bool SubString(SString& Sub, SString S, int pos, int len) {
	//子串范围越界
	if (pos + len - 1 > S.length) {
		return false;
	}
	for (int i = pos; i < pos + len; i++) {
		Sub.ch[i - pos + 1] = S.ch[i];
	}
	Sub.length = len;
	return true;
}

//比较操作
int StrCompare(SString S, SString T) {
	for (int i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i]) {
			return S.ch[i] - T.ch[i];
		}
	}
	return S.length - T.length;
}


//定位操作
int Index(SString S,SString T) {
	int i = 1, n = StrLength(S), m = strLength(T);
	SString sub;
	while (i <= n - m - 1) {
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0) {
			++i;
		}
		else
		{
			return i;
		}
		return 0;
	}
}


strAssign(&T, char s);//赋值操作
strCopy(&T, S);//复制操作
strEmpty(S);//判空操作

strLength(S)://求串长

ClearString(&S)://清空操作

DestroyString(&S)://销毁串

Concat(&T,S1,S2)://串联接


