//
// Created by Dashbah on 22.03.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

int levenshteinDistance(const std::string &s1, const std::string &s2) {
    auto n = s1.length();
    auto m = s2.length();
    std::vector<std::vector<int>> d(n + 1, std::vector<int>(m + 1, 0));
    for (size_t i = 0; i <= n; ++i) {
        d[i][0] = i;
    }
    for (size_t j = 0; j <= m; ++j) {
        d[0][j] = j;
    }
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = std::min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
            }
        }
    }
    return d[n][m];
}

int main() {
    std::string first, second;
    std::cin >> first >> second;
    std::cout << levenshteinDistance(first, second) << std::endl;
    return 0;
}
