//
// Created by Dashbah on 22.03.2023.
//

#include <iostream>
#include <algorithm>
#include <vector>

int levenshteinDistance(const std::string &s1, const std::string &s2) {
    auto len1 = static_cast<int>(s1.length());
    auto len2 = static_cast<int>(s2.length());
    int d[100][100];
    for (int i = 0; i <= len1; ++i) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; ++j) {
        d[0][j] = j;
    }
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = std::min(std::min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }
    return d[len1][len2];
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
