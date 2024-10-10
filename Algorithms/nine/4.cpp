#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countWays(int n, vector<pair<int, int>>& cards) {
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    // 初始状态
    dp[0][0] = 1; // 没有卡牌，和为 0
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {            
            // 选择正面
            dp[i][(j + cards[i - 1].first) % 3] = (dp[i][(j + cards[i - 1].first) % 3] + dp[i - 1][j]) % MOD;
            // 选择背面
            dp[i][(j + cards[i - 1].second) % 3] = (dp[i][(j + cards[i - 1].second) % 3] + dp[i - 1][j]) % MOD;
        }
    }
    
    return dp[n][0]; // 返回和为 0 的方案数
}

int main() {
    int n;
    cin >> n; // 输入卡牌数量
    vector<pair<int, int>> cards(n);
    
    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second; // 输入每张卡牌的正面和背面数字
    }
    
    cout << countWays(n, cards) << endl; // 输出方案数
    return 0;
}
