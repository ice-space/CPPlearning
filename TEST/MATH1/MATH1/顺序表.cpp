#include<stdio.h>
#include<stdlib.h>

//InitList(&L);初始化线性表
//DestroryList(&L)；销毁线性表
//“&”是否使用在于是否要将结果“带回来”
//sizeof(ElemType)  了解元素占用的内存大小


typedef int ElemType;

//静态分配
#define MaxSize 10
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;


////动态分配
//#define InitSize 10
//
//typedef struct {
//	/*ElemType* data;
//	int MaxSize;
//	int length;*/
//}SeqList;



//链表初始化
void InitList(SqList& L) {
	//动态初始化
	/*L.data = new ElemType[InitSize];
	L.length = 0;
	L.MaxSize = InitSize;*/
	//静态初始化

	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = 0;
	};
	L.length = 0;

};
//动态链表扩表
//void IncreaseSize(SeqList& L, int len) {
//	/*int* p = L.data;
//	L.data = new ElemType[(L.MaxSize + len)];
//	for (int i = 0; i < L.length; i++) {
//		L.data[i] = p[i];
//		L.MaxSize = L.MaxSize + len;
//	};
//	delete[](p);*/
//}


//数据表插入（静态）
bool ListInsert(SqList& L, int i, int e) {  //I表示数据表中的位序
	if (i<1 || i>L.length + 1) {	//判断I的范围是否有效
		return false;
	}
	if (L.length >= MaxSize) {		//当前空间已满，不能插入
		return false;
	}
	for (int j = L.length; j >= i; j--) {  //第I个元素及之后的元素后裔
		L.data[j] = L.data[j - 1];
	};
	L.data[i - 1] = e;		//插入元素
	L.length++;				//表长增加
	return true;
}

//数据表删除（静态）
bool ListDelete(SqList& L, int i, int& e) {  //I表示数据表中的位序
	if (i<1 || i>L.length + 1) {	//判断I的范围是否有效
		return false;
	}
	e = L.data[i - 1];

	for (int j = i; j <= L.length; j++) {  //第I个元素及之后的元素后裔
		L.data[j - 1] = L.data[j];
	};
	L.length--;				//表长增加
	return true;
}


//查找(位序）
bool GetElem(SqList L, int i) {
	if (i<1 || i>L.length) {								//判断查询的值是否合法
		return false;
	}
	printf("第i个元素的值为：%d\n", L.data[i - 1]);
	return true;
}


//按值查找
ElemType LocateElem(SqList L,ElemType e){
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
}




//主函数
int main() {
	
	//静态分配
	SqList L;
	
	InitList(L);
	for (int i = 0; i < MaxSize; i++) {
		printf("data[%d]=%d\n", i, L.data[i]);
	};

	//动态分配
	/*SeqList L;

	InitList(L);

	IncreaseSize(L, 5);*/

	//静态插入
	ListInsert(L, 1, 3);

	//静态删除
	int e = -1;

	if (ListDelete(L, 5, e)) {
		printf("已删除第3个元素，删除元素值为=%d\n", e);
	}
	else {
		printf("位序I不合法，删除失败\n");
	};

	return 0;
}






