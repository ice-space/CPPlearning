#include <iostream>
#include <algorithm>

using namespace std;

int findMaxSum(int n) {
    int max_sum = -1;

    for (int a1 = 0; a1 <= n; ++a1) {
        for (int a2 = 0; a2 <= n; ++a2) {
            if ((a1 + a2) % 2 == 0) {  // a1 + a2 is a multiple of 2
                for (int a3 = 0; a3 <= n; ++a3) {
                    if ((a2 + a3) % 3 == 0) {  // a2 + a3 is a multiple of 3
                        int total_sum = a1 + a2 + a3;
                        if (total_sum % 5 == 0) {  // a1 + a2 + a3 is a multiple of 5
                            max_sum = max(max_sum, total_sum);
                        }
                    }
                }
            }
        }
    }

    return max_sum;
}

int main() {
    int n;
    cin >> n;

    int result = findMaxSum(n);
    cout << result << endl;

    return 0;
}
