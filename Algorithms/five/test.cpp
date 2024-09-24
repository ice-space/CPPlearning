#include<bits/stdc++.h>

using namespace std;


// 物品结构体
struct Item {
    int value, weight;
    // 用于按价值密度排序
    bool operator<(const Item& other) const {
        return (double)value / weight > (double)other.value / other.weight;
    }
};


//贪心算法 // 由于当前是01背包问题所以物品不可分割
double greedyKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end()); // 按价值密度排序
    double totalValue = 0;
    int totalWeight = 0;

    for (const Item& item : items) {
        if (totalWeight + item.weight <= capacity) {
            totalWeight += item.weight;
            totalValue += item.value;
        } 
    //     else {
    //         // 取剩余空间的部分
    //         int remainingWeight = capacity - totalWeight;
    //         totalValue += item.value * (static_cast<double>(remainingWeight) / item.weight);
    //         break; // 背包已满
    //     }
    }
    return totalValue;
}

// 2. 回溯法
int backtrackKnapsack(const vector<Item>& items, int capacity, int i, int current_weight, int current_value, int max_value) {
    if (i == items.size()) {
        return max_value;
    }

    // 不选当前物品
    int notTake = backtrackKnapsack(items, capacity, i + 1, current_weight, current_value, max_value);

    // 选当前物品
    int take = 0;
    if (current_weight + items[i].weight <= capacity) {
        take = backtrackKnapsack(items, capacity, i + 1, current_weight + items[i].weight, current_value + items[i].value, max(current_value + items[i].value, max_value));
    }

    return max(notTake, take);
}




int main() {
    // 初始化物品和背包容量
    vector<Item> items = {{30, 20}, {10, 10}, {15, 20}};
    int capacity = 19;

    
    // 贪心算法
    cout << "Greedy Knapsack (fractional knapsack): " << greedyKnapsack(items, capacity) << endl;

    // // 回溯法
    cout << "Backtrack Knapsack (01 knapsack): " << backtrackKnapsack(items, capacity, 0, 0, 0, 0) << endl;

    // // 分支定界法
    // cout << "Branch and Bound Knapsack (01 knapsack): " << branchAndBoundKnapsack(items, capacity) << endl;

    return 0;
}