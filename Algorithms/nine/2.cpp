#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX; // 初始化为最大值
    int maxProfit = 0;      // 初始化为 0

    for (int price : prices) {
        minPrice = min(minPrice, price); // 更新最低价格
        maxProfit = max(maxProfit, price - minPrice); // 更新最大利润
    }

    return maxProfit; // 返回最大利润
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // 示例价格
    cout << "最大利润: " << maxProfit(prices) << endl; // 输出最大利润
    return 0;
}
