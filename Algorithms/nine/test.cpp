#include <iostream>
#include <vector>
#include <cmath>

const double EPSILON = 1e-9;
const double MAX_ERROR = 1e-4;

// Calculate probability distribution of damage for a given number of coins
std::vector<double> calculateDamageDistribution(int coins) {
    std::vector<double> prob(6 * coins + 1, 0.0);
    prob[0] = 1.0;
    for (int i = 1; i <= coins; ++i) {
        std::vector<double> newProb(prob.size(), 0.0);
        for (int j = 0; j < prob.size(); ++j) {
            for (int k = 1; k <= 6 && j + k < newProb.size(); ++k) {
                newProb[j + k] += prob[j] / 6.0;
            }
        }
        prob = std::move(newProb);
    }
    return prob;
}

double solve(int n, int h, const std::vector<std::pair<int, int>>& cards) {
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(h + 1, 0.0));
    dp[0][0] = 1.0;

    for (int i = 0; i < n; ++i) {
        auto& card = cards[i];
        if (card.first == 1) { // "时来运转"
            int coins = card.second;
            for (int j = 0; j <= h; ++j) {
                dp[i + 1][j] = dp[i][j];
            }
        } else if (card.first == 2) { // "幸运一掷"
            int coins = card.second;
            auto damageDist = calculateDamageDistribution(coins);
            for (int j = 0; j <= h; ++j) {
                for (int d = 0; d < damageDist.size(); ++d) {
                    if (j - d >= 0) {
                        dp[i + 1][j - d] += dp[i][j] * damageDist[d];
                    } else {
                        dp[i + 1][0] += dp[i][j] * damageDist[d];
                    }
                }
            }
        }
    }

    return dp[n][0];
}

int main() {
    int n, h;
    std::cin >> n >> h;
    std::vector<std::pair<int, int>> cards(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i].first >> cards[i].second;
    }

    std::cout.precision(10); // Set precision to ensure correct output format
    std::cout << solve(n, h, cards) << std::endl;

    return 0;
}