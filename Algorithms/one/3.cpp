#include<bits/stdc++.h>

using namespace std;

int dayofyear(int m, int d) {
    if (m <= 2) {
        return 31 * floor(m / 2) + d;
    } else if (m <= 7) {
        return 31 * floor(m / 2) + 30 * floor((m - 3) / 2) + 28 + d;
    } else {
        return 31 * ceil(m / 2) + 30 * floor((m - 4) / 2) + 28 + d;
    }
}

int main()
{
    int n;
    int bm,bd,em,ed;

    int jd;

    long bn;
    long bc;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> bm >> bd >> bn >> em >> ed;
        jd = dayofyear(em,ed) - dayofyear(bm,bd);
        bc = bn * pow(2,jd);
        cout << bc << endl;
    }
    return 0;
}