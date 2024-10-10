#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const double PROB_DICE = 1.0 / 6.0;

double countKillProbability(int n, int h, const vector<pair<int, int>>& cards) {
    int totalCoins = 0;       // 总的有效幸运币数
    int currentCoins = 0;     // 当前缓存的幸运币数
    int fixedDamage = 0;      // 固定伤害
    bool hasLuckyThrow = false; // 是否有“幸运一掷”卡牌

    // 遍历卡牌，统计幸运币和固定伤害
    for (const auto& card : cards) {
        if (card.first == 1) {
            currentCoins += card.second; // 累积当前的幸运币
        } else {
            // 遇到幸运一掷，将当前缓存的幸运币更新到总幸运币
            hasLuckyThrow = true;
            totalCoins += currentCoins;
            currentCoins = 0; // 清空当前幸运币缓存
            fixedDamage += card.second; // 增加固定伤害
        }
    }

    // 如果没有“幸运一掷”卡牌，无法造成伤害，直接返回 0
    if (!hasLuckyThrow) {
        return 0.0;
    }

    // 如果固定伤害已经大于或等于 h，直接返回 1
    if (fixedDamage >= h) {
        return 1.0;
    }

    // 检查幸运币是否有可能造成所需伤害
    if (totalCoins * 6 + fixedDamage < h) {
        return 0.0; // 幸运币即使全出6也无法造成足够的伤害
    }

    // 初始化 DP 数组
    vector<vector<double>> dp(totalCoins + 1, vector<double>(h - fixedDamage + 1, 0.0));
    dp[0][0] = 1.0; // 基本状态

    // 计算骰子投掷的结果
    for (int coins = 1; coins <= totalCoins; coins++) {
        for (int damage = 0; damage <= h - fixedDamage; damage++) {
            for (int k = 1; k <= 6; k++) {
                if (damage + k >= h - fixedDamage) {
                    dp[coins][h - fixedDamage] += dp[coins - 1][damage] * PROB_DICE; // 达到击杀条件
                } else {
                    dp[coins][damage + k] += dp[coins - 1][damage] * PROB_DICE; // 更新伤害
                }
            }
        }
    }

    // 计算最后的概率，返回造成伤害大于等于 h 的概率
    double totalProbability = dp[totalCoins][h - fixedDamage];

    return totalProbability;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> cards(n);

    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second;
    }

    double result = countKillProbability(n, h, cards);
    cout << fixed << setprecision(6) << result << endl; // 输出概率，保留6位小数
    return 0;
}
