//
// Created by Dashbah on 31.05.2023.
//
#include <iostream>

int main() {
    int64_t n, m;
    int a, b;
    std::cin >> m >> n >> a >> b;

    int64_t left = n - m;
    if (left <= 0) {
        std::cout << 0;
        return 0;
    }

    if (a <= b / 4.0) {
        std::cout << a * left;
        return 0;
    }

    int64_t sumFromMama = 0;
    sumFromMama += left / 4 * b;

    left %= 4;

    if (b <= a * left) {
        sumFromMama += b;
    } else {
        sumFromMama += a * left;
    }

    std::cout << sumFromMama;
}