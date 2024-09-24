#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 计算两个数与一个运算符的结果
double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b;
            else throw invalid_argument("Division by zero");
    }
    return 0;
}

// 检查所有可能的表达式是否可以得到24
bool checkExpression(double a, double b, double c, double d) {
    char ops[] = {'+', '-', '*', '/'};
    
    // 检查所有运算符组合和括号组合
    for (char op1 : ops) {
        for (char op2 : ops) {
            for (char op3 : ops) {
                // 四种括号组合
                double results[4];
                try {
                    // ((a op1 b) op2 c) op3 d
                    results[0] = applyOp(applyOp(applyOp(a, b, op1), c, op2), d, op3);
                    // (a op1 (b op2 c)) op3 d
                    results[1] = applyOp(applyOp(a, applyOp(b, c, op2), op1), d, op3);
                    // a op1 ((b op2 c) op3 d)
                    results[2] = applyOp(a, applyOp(applyOp(b, c, op2), d, op3), op1);
                    // a op1 (b op2 (c op3 d))
                    results[3] = applyOp(a, applyOp(b, applyOp(c, d, op3), op2), op1);

                    // 检查结果是否接近24
                    for (double res : results) {
                        if (fabs(res - 24.0) < 1e-6) {
                            return true;
                        }
                    }
                } catch (...) {
                    // 忽略除零错误
                }
            }
        }
    }
    return false;
}

bool canGet24(vector<int>& nums) {
    // 生成所有数字的排列
    sort(nums.begin(), nums.end());
    do {
        // 检查是否可以通过这些排列得到24
        if (checkExpression(nums[0], nums[1], nums[2], nums[3])) {
            return true;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    
    return false;
}

int main() {
    vector<int> numbers(4);
    while (true) {
        cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3];
        if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 && numbers[3] == 0) {
            break;
        }
        if (canGet24(numbers)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
