#include<stdio.h>
#include<stdlib.h>



#define MAX_TREE_SIZE 100

//双亲表示法（顺序存储）
//找双亲方便，找孩子不方便
typedef struct ElemTyde {
	int value;
}ElemType;

typedef struct {
	ElemType data;
	int parent;
}PTNode;


typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int n;
}PTree;






//孩子表示法（顺序+链式）
//找孩子方便找双亲不方便

struct CTNode {
	int child;										//孩子结点在数组中的位置
	struct CTNode* next;							//下一个孩子
};

typedef struct {
	ElemTyde data;
	struct CTNode* firstChild;
}CTBox;

typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;
}CTree;


//孩子兄弟表示法（链式存储）
typedef struct CSNode {
	ElemTyde data;												//数据域
	struct CSNode* firstchild, * nextibling;					//第一个孩子和右兄弟指针
}CSNode,CSTree;



