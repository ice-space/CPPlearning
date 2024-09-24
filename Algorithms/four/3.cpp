#include<bits/stdc++.h>
using namespace std;
int largestPerimeter(vector<int>& nums) {
    // 假设数组中的边长范围为 [1, 1000000]
    vector<int> count(1000001, 0);

    // 统计每个长度的频次
    for (int num : nums) {
        count[num]++;
    }

    // 从大到小遍历，寻找满足三角形不等式的组合
    vector<int> sortedNums;
    for (int i = 1000000; i > 0; i--) {
        while (count[i] > 0) {
            sortedNums.push_back(i);
            count[i]--;
        }
    }

    // 检查是否能组成三角形
    for (int i = 0; i < sortedNums.size() - 2; i++) {
        if (sortedNums[i] < sortedNums[i+1] + sortedNums[i+2]) {
            return sortedNums[i] + sortedNums[i+1] + sortedNums[i+2];
        }
    }

    return 0;
}

int main() {
    vector<int> nums = {3, 6, 2, 3};
    int result = largestPerimeter(nums);
    cout << "最大周长为: " << result << endl;
    return 0;
}