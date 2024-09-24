#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(const vector<int> &pos)
{
    int n = pos.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pos[i] == pos[j] || abs(pos[i] - pos[j]) == j - i)
            {
                return false;
            }
        }
    }
    return true;
}

void enumNQueens(int N)
{
    vector<int> pos(N);
    for (int i = 0; i < N; i++)
    {
        pos[i] = i; // 初始化排列
    }
    do
    {
        if (isValid(pos))
        {
            for (int i = 0; i < N; i++)
            {
                cout << pos[i] << " ";
            }
            cout << endl;
        }
    } while (next_permutation(pos.begin(), pos.end()));
}

int main()
{
    int N = 4; // 示例
    enumNQueens(N);
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, const vector<int> &pos)
{
    for (int i = 0; i < row; i++)
    {
        if (pos[i] == col || abs(pos[i] - col) == row - i)
        {
            return false;
        }
    }
    return true;
}

void backtrackNQueens(int N, int row, vector<int> &pos)
{
    if (row == N)
    {
        for (int i = 0; i < N; i++)
        {
            cout << pos[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col, pos))
        {
            pos[row] = col;
            backtrackNQueens(N, row + 1, pos);
        }
    }
}

int main()
{
    int N = 4; // 示例
    vector<int> pos(N);
    backtrackNQueens(N, 0, pos);
    return 0;
}
