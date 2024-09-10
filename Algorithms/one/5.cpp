#include <iostream>
#include <vector>
using namespace std;

// 判断是否存在冗余模数
bool isRedundant(int currentMod, int currentRem, const vector<int>& mods, const vector<int>& remainders) {
    for (int i = 0; i < mods.size(); i++) {
        // 如果 currentMod 是 mods[i] 的倍数，并且 remainders[i] 能被满足
        if (currentMod % mods[i] == 0 && currentRem % mods[i] == remainders[i]) {
            return true;  // currentMod 是冗余模数
        }
    }
    return false;
}

// 扩展欧几里得算法，用于求解 ax + by = gcd(a, b)
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// 求 a 在 mod m 下的逆元
int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, x, y);
    if (g != 1) {
        return -1;  // 如果 a 和 m 不是互质，则逆元不存在
    } else {
        return (x % m + m) % m;
    }
}

// 中国剩余定理求解
int findMinX(const vector<int>& num, const vector<int>& rem, int k) {
    // step 1: 计算所有模数的乘积
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= num[i];
    }

    // step 2: 根据中国剩余定理公式求解 x
    int result = 0;
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    // 原始模数数组
    vector<int> num = {2, 3, 5, 6, 7};
    
    // 原始余数数组
    vector<int> rem = {1, 2, 4, 5, 0};

    // 用于存储去除冗余后的模数和余数
    vector<int> simplifiedMods;
    vector<int> simplifiedRems;

    // 检查并去除冗余模数
    for (int i = 0; i < num.size(); i++) {
        if (!isRedundant(num[i], rem[i], simplifiedMods, simplifiedRems)) {
            simplifiedMods.push_back(num[i]);
            simplifiedRems.push_back(rem[i]);
        }
    }

    // 输出去除冗余后的模数和余数
    cout << "简化后的模数和余数: " << endl;
    for (int i = 0; i < simplifiedMods.size(); i++) {
        cout << "模数: " << simplifiedMods[i] << ", 余数: " << simplifiedRems[i] << endl;
    }

    // 计算最小 x
    int result = findMinX(simplifiedMods, simplifiedRems, simplifiedMods.size());

    cout << "楼梯的总台阶数是: " << result << endl;
    
    return 0;
}
