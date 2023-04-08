//
// Created by Dashbah on 13.02.2023.
// http://algolist.ru/maths/linalg/fmaxeminor.php
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> vec(n);

    int max = 1;
    int elem;
    vec[0] = std::vector<int>(m);
    std::cin >> elem;
    vec[0][0] = elem;
    for (int j = 1; j < m; ++j) {
        std::cin >> vec[0][j];
    }
    for (int i = 1; i < n; ++i) {
        vec[i] = std::vector<int>(m);
        std::cin >> vec[i][0];
        for (int j = 1; j < m; ++j) {
            std::cin >> vec[i][j];
            if (vec[i][j]) {
                vec[i][j] = std::min(vec[i][j - 1], vec[i - 1][j - 1]);
                vec[i][j] = std::min(vec[i][j], vec[i - 1][j]) + 1;
                if (vec[i][j] > max) {
                    max = vec[i][j];
                }
            }
        }
    }
    std::cout << max;
    return 0;
}
