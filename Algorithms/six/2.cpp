#include <iostream>
using namespace std;

// 斐波那契数列的动态规划实现
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // 定义数组来存储计算的斐波那契数列
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    // 计算从2到n的斐波那契数
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "输入n的值：";
    cin >> n;
    cout << "斐波那契数F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
