#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minTimeToCatchCow(int N, int K) {
    if (N >= K) {
        return N - K; // 如果农夫在牛的右边，只需线性移动
    }

    const int MAX_POSITION = 100000;
    vector<bool> visited(MAX_POSITION + 1, false);
    queue<pair<int, int>> q; // 存储位置和时间
    q.push({N, 0});
    visited[N] = true;

    while (!q.empty()) {
        int currentPosition = q.front().first;
        int currentTime = q.front().second;
        q.pop();

        // 检查是否抓住牛
        if (currentPosition == K) {
            return currentTime;
        }

        // 尝试三种移动方式
        // 移动到 X - 1
        if (currentPosition > 0 && !visited[currentPosition - 1]) {
            visited[currentPosition - 1] = true;
            q.push({currentPosition - 1, currentTime + 1});
        }

        // 移动到 X + 1
        if (currentPosition < MAX_POSITION && !visited[currentPosition + 1]) {
            visited[currentPosition + 1] = true;
            q.push({currentPosition + 1, currentTime + 1});
        }

        // 移动到 2 * X
        if (currentPosition * 2 <= MAX_POSITION && !visited[currentPosition * 2]) {
            visited[currentPosition * 2] = true;
            q.push({currentPosition * 2, currentTime + 1});
        }
    }

    return -1; // 如果未能找到，理论上不会发生
}

int main() {
    int N, K;
    cout << "输入农夫的位置N和牛的位置K: ";
    cin >> N >> K;
    int result = minTimeToCatchCow(N, K);
    cout << "农夫抓到牛所需的最少时间: " << result << " 分钟" << endl;
    return 0;
}
