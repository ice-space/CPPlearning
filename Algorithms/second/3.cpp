#include <iostream>
#include <vector>
#include <queue>
#include <functional> // For std::greater

using namespace std;

// 函数来输出数组中前 k 大的元素
void printTopKElements(const vector<int>& arr, int k) {
    if (k <= 0 || arr.empty()) {
        cout << "NO" << endl;
        return;
    }
    
    // 定义一个最小堆（优先队列）
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // 遍历数组中的每个元素
    for (int num : arr) {
        if (minHeap.size() < k) {
            minHeap.push(num); // 堆的大小小于 k，直接插入
        } else if (num > minHeap.top()) {
            minHeap.pop();    // 移除堆中的最小元素
            minHeap.push(num); // 插入新元素
        }
    }

    // 将堆中的元素存入一个向量中
    vector<int> topKElements;
    while (!minHeap.empty()) {
        topKElements.push_back(minHeap.top());
        minHeap.pop();
    }

    // 反转向量使其从大到小排序
    reverse(topKElements.begin(), topKElements.end());

    // 输出结果
    for (int num : topKElements) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 1, 3, 7, 9, 2, 6, 8};
    int k = 3; // 查找前 k 大的数

    printTopKElements(arr, k);

    return 0;
}
