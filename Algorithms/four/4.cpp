#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums;
    int temp;

    cout << "请输入整数，非整数结束输入:" << endl;

    while (cin >> temp && !cin.fail()) {
        nums.push_back(temp);
    }
   

    // 输入流状态检查，可以处理输入结束后的情况
    if (cin.fail() && !cin.eof()) {
        cout << "检测到无效输入，输入结束。" << endl;
    }

    cout << "输入的数字为: ";
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
