//
// Created by Dashbah on 19.10.2022.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
int bin(const std::vector<int>& vec, int x, int len) {
    if (x < vec[0]) {
        return 0;
    }
    int left = 0;
    int right = len - 1;
    while (left<right) {
        int m = (left + right + 1) / 2;
        if (vec[m] <= x) {
            left = m;
        } else {
            right = m - 1;
        }
    }
    return left + 1;
}



double median(const std::vector<int>& first, const std::vector<int>& second, int len) {
    int left = std::min(first[0], second[0]);
    int right = std::max(first[len-1], second[len-1]);
    while (left < right) {
        int m = (left + right) / 2;
        if (bin(first, m, len) + bin(second, m, len) >= len) {
            right = m;
        } else {
            left = m + 1;
        }
    }
    int l = first[bin(first, left, len)];
    int r = second[bin(second, left, len)];
    return (left + std::min(l, r) + 0.0) / 2;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> lines;
    lines.resize(n);
    for (auto &line: lines) {
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
    std::cout << bin(lines[2], 48, m);
}
//        n, l = map(int, input().split())
//arr = []
//for i in range(n):
//x1, d1, a, c, m = map(int, input().split())
//d = d1
//arr.append([x1])
//for j in range(1, l):
//arr[i].append(arr[i][j - 1] + d)
//d = (a * d + c) % m
//for i in range(n):
//for j in range(i + 1, n):
//print(median(arr[i], arr[j]))