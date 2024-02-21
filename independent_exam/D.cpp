//
// Created by Dashbah on 31.05.2023.
//
#include <iostream>
#include <vector>

int main() {
    int l, n, m;
    std::cin >> l >> n >> m;

    std::vector<int> edges(l);
    int left, right;
    for (int i = 0; i < n; ++i) {
        std::cin >> left >> right;
        ++edges[left - 1];
        --edges[right];
    }

    int sum = 0;
    std::vector<int> tolsch(l);
    for (int i = 0; i < l; ++i) {
        sum += edges[i];
        tolsch[i] = sum;
    }

    int coordinate;
    for (int i = 0; i < m; ++i) {
        std::cin >> coordinate;
        std::cout << tolsch[coordinate - 1] << std::endl;
    }


}