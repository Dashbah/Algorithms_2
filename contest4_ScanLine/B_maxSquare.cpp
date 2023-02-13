//
// Created by Dashbah on 13.02.2023.
//
#include <iostream>
#include <vector>

int maxInArea(const std::vector<std::vector<int>> &vec, size_t line, size_t column, size_t len,
              const size_t max) {
    int curr_max = 1;
    for (size_t i = line + 1; i < line + len && i < vec.size(); ++i) {
        for (size_t j = column; j < column + len && j < vec[0].size(); ++j) {
            if (vec[i][j] == 0) {
                int left_max = 0;
                int right_max = 0;
                if (j - column > max && j - column >= i - line + 1) {
                    left_max = maxInArea(vec, i, column, j - column, max);
                }
                if (len - j > max && len - j - 1 >= i - line + 1) {
                    right_max = maxInArea(vec, i, j + 1, len - j + column, max);
                }
                curr_max += std::max(left_max, right_max);
                return curr_max;
            }
        }
        ++curr_max;
    }
    return curr_max;
}

int bFunc(const std::vector<std::vector<int>> &vec) {
    size_t max = 1;
    size_t num_of_ones;
    for (size_t i = 0; i + max < vec.size() + 1; ++i) {
        num_of_ones = 0;
        for (size_t j = 0; j < vec[0].size(); ++j) {
            if (vec[i][j] == 1) {
                ++num_of_ones;
            } else {
                if (num_of_ones > max) {
                    size_t curr_max = maxInArea(vec, i, j - num_of_ones, num_of_ones, max);
                    max += (curr_max > max) ? curr_max : max;
                }
                num_of_ones = 0;
            }
        }
        if (num_of_ones == vec[0].size()) {
            ++max;
        }
    }
    return max;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = std::vector<int>(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> vec[i][j];
        }
    }

    // std::cout << maxInArea(vec, 0, 0, vec[0].size(), 1);
    std::cout << bFunc(vec);
    return 0;
}