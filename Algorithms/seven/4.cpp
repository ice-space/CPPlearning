#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n == 0) return 0;
    if (n == 1) return cost[0];

    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    // 最小花费是到达最后一个或倒数第二个阶梯的最小值
    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    vector<int> cost = {10, 15, 20};
    cout << "达到顶部的最低花费是: " << minCostClimbingStairs(cost) << endl;
    return 0;
}
