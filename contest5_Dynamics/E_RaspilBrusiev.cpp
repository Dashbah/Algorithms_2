//
// Created by Dashbah on 28.02.2023.
//
#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int l, n;
    std::cin >> l >> n;
    std::vector<int> lengths(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        std::cin >> lengths[i];
    }
    lengths.emplace_back(l);
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
    for (int i = 2; i < n + 2; ++i) {
        for (int j = 0; j < n - i + 2; ++j) {
            int min = INT_MAX;
            for (int k = j + 1; k < j + i; ++k) {
                int temp = dp[j][k] + dp[k][j + i];
                if (temp < min) {
                    min = temp;
                }
            }
            dp[j][j + i] = min + lengths[j + i] - lengths[j];
        }
    }
    std::cout << dp[0].back() << std::endl;
    return 0;
}