#include<stdio.h>

#define MaxSize 100
typedef int ElemType;


struct TreeNode {
	ElemType value;//结点中的数组元素
	bool isEmpty;//结点是否未空
};

int main() {
	TreeNode t[MaxSize];
	for (int i = 0; i < MaxSize; i++) {
		t[i].isEmpty = true;
	}
}


//二叉树的顺序结构只适合完全二叉树








