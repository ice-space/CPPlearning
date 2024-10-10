#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;

    // 处理 k 大于 n / 2 的情况
    if (k > n / 2) {
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));

    // 初始化状态
    for (int j = 1; j <= k; j++) {
        dp[0][j][1] = INT_MIN; // 不可能在第 0 天持有股票
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            // 不持有股票
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
            // 持有股票
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
        }
    }
    
    return dp[n][k][0]; // 最后一天不持有股票的最大利润
}

int main() {
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << "最大利润: " << maxProfit(k, prices) << endl;
    return 0;
}
