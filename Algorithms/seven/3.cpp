#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; // 物品数量
    int W; // 背包容量
    cin >> n >> W;

    vector<int> v(n + 1); // 物品价值
    vector<int> w(n + 1); // 物品重量

    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i]; // 输入每个物品的价值和重量
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // 动态规划填表
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // 最优解
    int maxValue = dp[n][W];
    cout << "最大价值: " << maxValue << endl;

    // 追踪选取的物品
    vector<int> selectedItems;
    int j = W;
    for (int i = n; i > 0; --i) {
        if (dp[i][j] != dp[i - 1][j]) {
            selectedItems.push_back(i); // 物品 i 被选择
            j -= w[i];
        }
    }

    cout << "选取的物品: ";
    for (int i = selectedItems.size() - 1; i >= 0; --i) {
        cout << selectedItems[i] << " ";
    }
    cout << endl;

    return 0;
}
