/**
 * @Author: Yuan
 * @Date: 2024-09-23 21:04:22
 * @LastEditors: Yuan
 * @LastEditTime: 2024-09-25 16:28:59
 * @Description: 
 * @版权声明: icespaceworking@163.com
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 物品结构体
struct Item
{
    int value, weight;
    // 用于按价值密度排序
    bool operator<(const Item &other) const
    {
        return (double)value / weight > (double)other.value / other.weight;
    }
};

// 1. 贪心算法（适用于分数背包问题，非01背包问题）
double greedyKnapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end()); // 按价值密度排序
    double totalValue = 0;
    int totalWeight = 0;

    for (const Item &item : items)
    {
        if (totalWeight + item.weight <= capacity)
        {
            totalWeight += item.weight;
            totalValue += item.value;
        }
        // else {
        //     // 取剩余空间的部分
        //     int remainingWeight = capacity - totalWeight;
        //     totalValue += item.value * (static_cast<double>(remainingWeight) / item.weight);
        //     break; // 背包已满
        // }
    }
    return totalValue;
}

// 2. 回溯法
int backtrackKnapsack(const vector<Item> &items, int capacity, int i, int current_weight, int current_value, int max_value)
{
    if (i == items.size())
    {
        return max_value;
    }
    // 不选当前物品
    int notTake = backtrackKnapsack(items, capacity, i + 1, current_weight, current_value, max_value);
    // 选当前物品
    int take = 0;
    if (current_weight + items[i].weight <= capacity)
    {
        take = backtrackKnapsack(items, capacity, i + 1, current_weight + items[i].weight, current_value + items[i].value, max(current_value + items[i].value, max_value));
    }
    return max(notTake, take);
}

// 3. 分支定界法中的节点结构体
struct Node
{
    int level, value, weight;
    double bound;
    Node(int lvl, int val, int wgt, double bnd) : level(lvl), value(val), weight(wgt), bound(bnd) {}
};

// 计算节点的上界
double bound(Node u, int capacity, const vector<Item> &items)
{
    if (u.weight >= capacity)
        return 0;
    double bound = u.value;
    int j = u.level + 1;
    int totalWeight = u.weight;
    while (j < items.size() && totalWeight + items[j].weight <= capacity)
    {
        totalWeight += items[j].weight;
        bound += items[j].value;
        j++;
    }
    if (j < items.size())
    {
        bound += (capacity - totalWeight) * ((double)items[j].value / items[j].weight);
    }
    return bound;
}

// 3. 分支定界法
int branchAndBoundKnapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end());
    queue<Node> q;
    Node u(-1, 0, 0, 0);
    u.bound = bound(u, capacity, items);
    q.push(u);

    int maxValue = 0;

    while (!q.empty())
    {
        Node u = q.front();
        q.pop();
        if (u.level == -1 || u.weight <= capacity)
        {
            if (u.level == items.size() - 1)
                continue;
            // 子节点选择当前物品
            Node v(u.level + 1, u.value + items[u.level + 1].value, u.weight + items[u.level + 1].weight, 0);
            if (v.weight <= capacity && v.value > maxValue)
            {
                maxValue = v.value;
            }
            v.bound = bound(v, capacity, items);
            if (v.bound > maxValue)
            {
                q.push(v);
            }
            // 子节点不选择当前物品
            Node w(u.level + 1, u.value, u.weight, 0);
            w.bound = bound(w, capacity, items);
            if (w.bound > maxValue)
            {
                q.push(w);
            }
        }
    }
    return maxValue;
}

int main()
{
    // 初始化物品和背包容量
    vector<Item> items = {{30, 20}, {10, 10}, {15, 20}};
    int capacity = 25;
    // 贪心算法
    cout << "Greedy Knapsack (fractional knapsack): " << greedyKnapsack(items, capacity) << endl;
    // 回溯法
    cout << "Backtrack Knapsack (01 knapsack): " << backtrackKnapsack(items, capacity, 0, 0, 0, 0) << endl;
    // 分支定界法
    cout << "Branch and Bound Knapsack (01 knapsack): " << branchAndBoundKnapsack(items, capacity) << endl;
    return 0;
}
