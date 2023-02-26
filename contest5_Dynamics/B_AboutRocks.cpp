//
// Created by Dashbah on 24.02.2023.
//
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, w;
    std::cin >> n >> w;
    std::vector<int> rocks(n);
    for (auto &rock : rocks) {
        std::cin >> rock;
    }

    std::vector<std::vector<int>> vec;
    vec.emplace_back(std::vector<int>(w + 1));
    for (int i = 1; i <= n; ++i) {
        vec.emplace_back(std::vector<int>(w + 1));
        for (int j = 1; j <= w; ++j) {
            if (rocks[i - 1] <= j) {
                vec[i][j] = std::max(vec[i - 1][j], vec[i - 1][j - rocks[i - 1]] + rocks[i - 1]);
            } else {
                vec[i][j] = vec[i - 1][j];
            }
        }
    }

    std::cout << vec.back().back() << std::endl;

    std::vector<int> res;
    int i = n, j = w;
    while (vec[i][j] != 0) {
        if (vec[i][j] != vec[i - 1][j]) {
            j -= rocks[i - 1];
            res.emplace_back(rocks[i - 1]);
            --i;
        } else {
            --i;
        }
    }

    std::cout << res.size() << std::endl;
    for (int place = static_cast<int>(res.size()) - 1; place >= 0; --place) {
        std::cout << res[place] << " ";
    }
    return 0;
}
