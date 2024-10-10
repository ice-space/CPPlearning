#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    // dp数组初始化，每个位置的初始长度为1
    vector<int> dp(n, 1);
    
    // 状态转移方程的实现
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 找到dp数组中的最大值，即为LIS的长度
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "最长递增子序列的长度是: " << lengthOfLIS(nums) << endl;
    return 0;
}
