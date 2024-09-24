#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findClosestElement(const vector<int>& sequence, int value) {
    int left = 0;
    int right = sequence.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sequence[mid] == value) {
            return sequence[mid];
        } else if (sequence[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (left >= sequence.size()) {
        return sequence[right];
    } else if (right < 0) {
        return sequence[left];
    } else {
        if (abs(sequence[left] - value) < abs(sequence[right] - value)) {
            return sequence[left];
        } else if (abs(sequence[left] - value) > abs(sequence[right] - value)) {
            return sequence[right];
        } else {
            return min(sequence[left], sequence[right]);
        }
    }
}

int main() {
    int n, m;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    cin >> m;
    
    for (int i = 0; i < m; ++i) {
        int query_value;
        cin >> query_value;
        cout << findClosestElement(sequence, query_value) << endl;
    }

    return 0;
}
