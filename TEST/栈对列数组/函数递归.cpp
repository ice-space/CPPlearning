#include<stdio.h>


int func2(int x) {
	int m, n;
	m = x + 1;
	n = x + 2;
}


int func1(int a, int b) {
	//a:1 b : 2
	int x = a + b;  //x:3
	func2(x);
	x = x + 10086;
}


//阶乘算法
int facorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * facorial(n - 1);
	}
}


//递归算法求斐波那契欸数列
int Fib(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}



int main() {

	//递归原理
	int a = 1, b = 2, c = 3;
	func1(a, b);
	c = a + b;

	//求阶乘 递归算法
	int x = facorial(10);
	printf("奥里给！");

	//递归算法求斐波那契欸数列
	int x = Fib(4);
	printf("奥里给！");

}