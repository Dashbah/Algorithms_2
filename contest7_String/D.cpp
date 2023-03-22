//
// Created by Dashbah on 22.03.2023.
//

#include <iostream>
#include <algorithm>
#include <vector>

int levenshteinDistance(const std::string &s1, std::string &s2) {
    auto n = static_cast<int>(s1.length());
    auto m = static_cast<int>(s2.length());
    std::vector<std::vector<int>> d(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = std::min(std::min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
            }
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                d[i][j] = std::min(d[i][j], d[i - 2][j - 2] + 1);
            }
        }
    }

    return d[n][m];
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        std::string first, second;
        std::cin >> first >> second;
        int distance = levenshteinDistance(first, second);
        std::cout << distance << " ";
    }

    std::string first, second;
    std::cin >> first >> second;
    int distance = levenshteinDistance(first, second);
    std::cout << distance;

    return 0;
}

