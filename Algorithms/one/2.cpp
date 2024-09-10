#include<bits/stdc++.h>

using namespace std;

auto square_sum(int n){
    return n*(n+1)*(2*n+1)/6;
};

int main() {
    vector<int> seven_related_numbers = {7, 14, 17, 21, 27, 28, 35, 37, 42, 47, 49, 56, 57, 63, 67, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 84, 87, 91, 92, 95, 97, 98};

    int n;
    cin >> n;

    // 计算所有数的平方和
    long long total_square_sum = square_sum(n);

    // 计算需要排除的数的平方和
    long long excluded_square_sum = 0;
    for (int num : seven_related_numbers) {
        if (num <= n) {
            excluded_square_sum += num * num; // 直接计算平方
        }
    }

    // 计算最终结果
    long long result = total_square_sum - excluded_square_sum;

    // 输出结果
    cout << result << endl;

    return 0;
}