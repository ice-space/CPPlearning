#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; // 行数
    cin >> n;

    vector<vector<int>> pyramid(n); // 定义金字塔

    // 读取金字塔输入
    for (int i = 0; i < n; i++) {
        pyramid[i] = vector<int>(i + 1);
        for (int j = 0; j < i + 1; j++) {
            cin >> pyramid[i][j];
        }
    }

    // 动态规划，从倒数第二行开始向上计算最大路径和
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // 当前点的最大和等于当前点加上下面两个点的最大和
            pyramid[i][j] += max(pyramid[i + 1][j], pyramid[i + 1][j + 1]);
        }
    }

    // 输出位于金字塔顶点的最大路径和
    cout << pyramid[0][0] << endl;

    return 0;
}
