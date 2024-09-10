#include <bits/stdc++.h>
using namespace std;

void findCounterfeitCoin(vector<vector<vector<string>>> &testCases) {
    unordered_map<char, bool> isTrue;
    unordered_map<char, int> weight;  // 0: 未知, 1: 轻, 2: 重
    for (auto &test : testCases) {

        
        // 初始化所有硬币为假币候选
        for (char c = 'A'; c <= 'L'; ++c) {
            isTrue[c] = false;  // 初始化假设都为假币
            weight[c] = 0;  // 0 表示未知
        }

        // 遍历每次称量
        for (auto &weighing : test) {
            string left = weighing[0], right = weighing[1], balance = weighing[2];
            set<char> involved;  // 用来记录参与称量的硬币

            for (char c : left + right) {
                involved.insert(c);
            }

            if (balance == "even") {
                // 如果天平平衡，左右两边硬币都是真币
                for (char c : left + right) {
                    isTrue[c] = true;
                }
            } else {
                // 如果不平衡，左边和右边参与称量的硬币根据结果进行推测
                if (balance == "up") {
                    // 左边重，右边轻
                    for (char c : left) {
                        if (!isTrue[c]) weight[c] = 2;  // 重
                    }
                    for (char c : right) {
                        if (!isTrue[c]) weight[c] = 1;  // 轻
                    }
                } else if (balance == "down") {
                    // 左边轻，右边重
                    for (char c : left) {
                        if (!isTrue[c]) weight[c] = 1;  // 轻
                    }
                    for (char c : right) {
                        if (!isTrue[c]) weight[c] = 2;  // 重
                    }
                }

                // 除了已经被判断为真币的硬币，剩下未参与称量的硬币都是真币
                for (char c = 'A'; c <= 'L'; ++c) {
                    if (involved.find(c) == involved.end()) {
                        isTrue[c] = true;  // 标记未参与称量的硬币为真币
                    }
                }
            }
        }
    }
    // 查找唯一的假币
    char counterfeit = 0;
    string result;
    for (char c = 'A'; c <= 'L'; ++c) {
        if (!isTrue[c] && weight[c] != 0) {  // 不是真币且标记为轻或重
            counterfeit = c;
            result = (weight[c] == 1) ? "light" : "heavy";
            break;
        }
    }
    cout << counterfeit << " is the counterfeit coin and it is " << result << "." << endl;
}

int main() {
    int t;
    cin >> t;  // 输入测试组数
    vector<vector<vector<string>>> testCases;  // 保存所有测试用例

    for (int i = 0; i < t; ++i) {
        vector<vector<string>> test(3, vector<string>(3));  // 每个测试有三次称量
        for (int j = 0; j < 3; ++j) {
            string left, right, balance;
            cin >> left >> right >> balance;
            test[j] = {left, right, balance};  // 保存每次称量的结果
        }
        testCases.push_back(test);  // 保存每个测试用例
    }

    findCounterfeitCoin(testCases);

    return 0;
}
