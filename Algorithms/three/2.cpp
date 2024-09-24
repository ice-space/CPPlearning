#include<bits/stdc++.h>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

// 选择排序函数
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 冒泡排序函数
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 去重函数
vector<int> removeDuplicates(vector<int>& arr) {
    vector<int> uniqueElements;
    for (int num : arr) {
        if (uniqueElements.empty() || num != uniqueElements.back()) {
            uniqueElements.push_back(num);
        }
    }
    return uniqueElements;
}

int main() {
    int n;
    cin >> n;  // 输入ISBN的数量

    vector<int> isbn(n);
    for (int i = 0; i < n; ++i) {
        cin >> isbn[i];  // 输入ISBN号
    }

    // 使用选择排序对ISBN进行排序
    selectionSort(isbn);

    // 使用冒泡排序对ISBN进行排序
    bubbleSort(isbn);

    // 去重处理
    vector<int> sortedISBN = removeDuplicates(isbn);

    // 输出不重复的ISBN数量
    cout << sortedISBN.size() << endl;

    // 输出已排序的不重复ISBN
    for (int i = 0; i < sortedISBN.size(); ++i) {
        cout << sortedISBN[i] << " ";
    }
    cout << endl;

    return 0;
}

