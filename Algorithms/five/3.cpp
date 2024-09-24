#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Item
{
    int SN, attribute_x, attribute_y;
    vector<int> cookbook;

    Item(int S, int x, int y, vector<int> cb)
        : SN(S), attribute_x(x), attribute_y(y), cookbook(cb) {}

    bool operator<(const Item &other) const
    {
        if ((double)attribute_x / attribute_y == (double)other.attribute_x / other.attribute_y)
        {
            return accumulate(cookbook.begin(), cookbook.end(), 0) <
                   accumulate(other.cookbook.begin(), other.cookbook.end(), 0);
        }
        return (double)attribute_x / attribute_y > (double)other.attribute_x / other.attribute_y;
    }
};

int backtrack(int idx, const vector<Item> &cooks, int current_x, int current_y, vector<int> &materials, int limit)
{
    if (idx >= cooks.size())
    {
        return (current_y >= limit) ? current_x : 0; // 结束时判断是否满足饱腹感
    }

    // 不选择当前料理
    int maxDeliciousness = backtrack(idx + 1, cooks, current_x, current_y, materials, limit);

    // 尝试选择当前料理
    bool canCook = true;
    for (int j = 0; j < materials.size(); j++)
    {
        if (materials[j] < cooks[idx].cookbook[j])
        {
            canCook = false; // 食材不够，无法制作当前料理
            break;
        }
    }

    if (canCook)
    {
        // 更新材料
        for (int j = 0; j < materials.size(); j++)
        {
            materials[j] -= cooks[idx].cookbook[j]; // 减去食材
        }

        // 递归选择当前料理
        int newDeliciousness = backtrack(idx + 1, cooks, current_x + cooks[idx].attribute_x, current_y + cooks[idx].attribute_y, materials, limit);

        // 更新最大美味度
        maxDeliciousness = max(maxDeliciousness, newDeliciousness);

        // 恢复材料
        for (int j = 0; j < materials.size(); j++)
        {
            materials[j] += cooks[idx].cookbook[j]; // 恢复食材
        }
    }

    return maxDeliciousness; // 返回最大美味度
}

int main()
{
    // 示例数据
    vector<int> materials = {10, 10, 10, 10, 10}; // 食材数量
    vector<vector<int>> cookbooks = {
        {1, 1, 1, 1, 1},      // 料理0
        {3, 3, 3, 3, 3},      // 料理1
        {10, 10, 10, 10, 10}, // 料理2
    };
    vector<vector<int>> attribute = {
        {5, 5},   // 料理0
        {6, 6},   // 料理1
        {10, 10}, // 料理2
    };
    int limit = 1; // 饱腹感下限

    vector<Item> cooks;
    for (int i = 0; i < cookbooks.size(); i++)
    {
        cooks.emplace_back(i, attribute[i][0], attribute[i][1], cookbooks[i]);
    }

    // 对食物进行排序
    sort(cooks.begin(), cooks.end());

    int maxDeliciousness = backtrack(0, cooks, 0, 0, materials, limit);

    cout << (maxDeliciousness > 0 ? maxDeliciousness : -1) << endl;

    return 0;
}
