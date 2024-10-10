#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // dp 数组，初始值都为1
    vector<int> dp(n, 1);

    // 动态规划过程，更新 dp 数组
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 获取 dp 数组中的最大值，即最长上升子序列的长度
    int lis_length = *max_element(dp.begin(), dp.end());
    cout << lis_length << endl;

    return 0;
}
