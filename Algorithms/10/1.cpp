#include <iostream>
#include <vector>
using namespace std;

const int wallMask[] = {1, 2, 4, 8}; // 西、北、东、南

int m, n; // 行数和列数
vector<vector<int>> grid; // 城堡的墙壁状态
vector<vector<bool>> visited; // 访问状态
int roomCount = 0; // 房间数
int maxRoomSize = 0; // 最大房间大小

// DFS 搜索
int DFS(int x, int y) {
    visited[x][y] = true;
    int size = 1; // 当前房间大小
    for (int i = 0; i < 4; i++) { // 0:西, 1:北, 2:东, 3:南
        int newX = x + (i == 0 ? 0 : (i == 1 ? -1 : (i == 2 ? 0 : 1)));
        int newY = y + (i == 0 ? -1 : (i == 1 ? 0 : (i == 2 ? 1 : 0)));
        
        // 检查是否在边界内
        if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

        // 检查是否有墙壁阻挡
        if ((grid[x][y] & wallMask[i]) == 0 && !visited[newX][newY]) {
            size += DFS(newX, newY); // 递归访问
        }
    }
    return size;
}

int main() {
    cin >> m >> n;
    grid.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n, false));

    // 输入城堡的墙壁状态
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 遍历所有方块，进行 DFS
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) { // 如果未访问过
                roomCount++; // 新房间
                int roomSize = DFS(i, j); // 计算房间大小
                maxRoomSize = max(maxRoomSize, roomSize); // 更新最大房间大小
            }
        }
    }

    // 输出房间数和最大房间大小
    cout << roomCount << endl;
    cout << maxRoomSize << endl;

    return 0;
}
