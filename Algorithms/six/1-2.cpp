#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;  // 地窖数量
    cin >> n;
    
    vector<int> mines(n + 1); // 每个地窖的地雷数，1-based index
    for (int i = 1; i <= n; ++i) {
        cin >> mines[i];
    }

    vector<vector<int>> adj(n + 1); // 邻接表存储地窖的连接关系
    int xi, yi;
    while (cin >> xi >> yi, xi != 0 || yi != 0) {
        adj[xi].push_back(yi);
    }

    vector<int> dp(n + 1, 0); // dp[i]表示从第i个地窖挖到的最多地雷数
    vector<int> pre(n + 1, -1); // pre[i]记录第i个地窖的前驱地窖，方便回溯路径

    // 初始化dp，每个地窖从自身开始挖，初始地雷数就是自身地雷数
    for (int i = 1; i <= n; ++i) {
        dp[i] = mines[i];
    }

    // 动态规划处理路径
    for (int i = 1; i <= n; ++i) {
        for (int next : adj[i]) {
            if (dp[next] < dp[i] + mines[next]) {
                dp[next] = dp[i] + mines[next];
                pre[next] = i; // 记录路径
            }
        }
    }

    // 找到能挖到最多地雷的地窖
    int max_mines = 0, end = 1;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > max_mines) {
            max_mines = dp[i];
            end = i;
        }
    }

    // 通过pre数组回溯路径
    vector<int> path;
    for (int i = end; i != -1; i = pre[i]) {
        path.push_back(i);
    }

    // 输出结果
    reverse(path.begin(), path.end()); // 路径需要逆序输出
    for (int i = 0; i < path.size(); ++i) {
        if (i > 0) cout << "-";
        cout << path[i];
    }
    cout << endl;

    cout << "最大地雷数: " << max_mines << endl;

    return 0;
}


