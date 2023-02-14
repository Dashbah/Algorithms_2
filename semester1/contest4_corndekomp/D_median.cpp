//
// Created by Dashbah on 19.10.2022.
//
#include <vector>
#include <iostream>
#include <iomanip>
// consa
// #include <limits>
// Github copilot


double median(const std::vector<int> &left, const std::vector<int> &right, int m) {
    int result = 0;
    int curr_left = 0;
    int curr_right = 0;
    for (auto i = 0; i < m; ++i) {
        if (left[curr_left] < right[curr_right]) {
            result = left[curr_left++];
        } else {
            result = right[curr_right++];
        }
    }
    if (left[curr_left] < right[curr_right]) {
        return (result + left[curr_left] + 0.0) / 2;
    } else {
        return (result + right[curr_right] + 0.0) / 2;
    }
}

int main() {
    // double y = std::numeric_limits<double>();
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> lines;
    lines.resize(n);
    for (auto &line : lines) {
        line.resize(m);
    }
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            std::cin >> lines[i][j];
        }
    }
    std::cout << std::fixed << std::setprecision(5);
    for (auto left = 0; left < n - 1; ++left) {
        for (auto right = left + 1; right < n; ++right) {
            std::cout << median(lines[left], lines[right], m) << '\n';
        }
    }
}
