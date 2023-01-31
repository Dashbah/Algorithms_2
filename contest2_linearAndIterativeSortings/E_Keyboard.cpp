#include <iostream>
#include <vector>

//
// Created by Dashbah on 31.01.2023.
//
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    int k;
    std::cin >> k;
    int key;
    for (int i = 1; i < k + 1; ++i) {
        std::cin >> key;
        --vec[key - 1];
    }

    for (int i = 0; i < n; ++i) {
        if (vec[i] >= 0) {
            std::cout << "no" << std::endl;
        } else {
            std::cout << "yes" << std::endl;
        }
    }
}