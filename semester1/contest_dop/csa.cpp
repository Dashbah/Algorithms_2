//
// Created by Dashbah on 21.10.2022.
//
#include <array>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> a;
    int n = 10;
    for (int i = 0; i < n; ++i) {
        a.emplace_back(i);
    }
    for (auto num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    double arifm = 0;
    for (int i = 0; i < n; ++i) {
        arifm += a[i];
    }
    arifm /= n;
    // std::cout << arifm << " " << std::endl;
    int sum = a[0];
    std::vector<int> b;
    for (int i = 0; a[i] <= arifm && i < n; ++i) {
        sum += a[i + 1];
        b.emplace_back(sum);
    }
    for (auto num : b) {
        std::cout << num << " ";
    }
}
