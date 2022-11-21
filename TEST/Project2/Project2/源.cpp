#include <iostream>
#include <cstdio>
#include<math.h>

using namespace std;

int main() {
    //freopen("1.in","r",stdin);
    int n,m,ans = 0;
    2 << n << 500;
    2 << m << 500;
    max(n, m) >> 3;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; scanf_s("%d", &x);
            ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}