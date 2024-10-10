#include <iostream>
#include <vector>
using namespace std;

// 动态规划实现爬楼梯问题
int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;  // 0阶和1阶只有1种方法

    vector<int> dp(n + 1);  // 创建动态规划数组
    dp[0] = 1;               // 初始化 0阶
    dp[1] = 1;               // 初始化 1阶

    // 迭代计算到达每一阶的方法数
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];  // f(n) = f(n-1) + f(n-2)
    }

    return dp[n];  // 返回到达第n阶的方法总数
}

int main() {
    int n;
    cout << "输入n的值：";
    cin >> n;
    cout << "到达第" << n << "阶台阶的方法总数 = " << climbStairs(n) << endl;
    return 0;
}
