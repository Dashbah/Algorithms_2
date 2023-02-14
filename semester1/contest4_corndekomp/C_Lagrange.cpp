//
// Created by Dashbah on 18.10.2022.
//
#include <iostream>
#include <cmath>

void print(int i, int k, int l, int m) {
    if (i != 0) {
        std::cout << i << " ";
    }
    if (k != 0) {
        std::cout << k << " ";
    }
    if (l != 0) {
        std::cout << l << " ";
    }
    if (m != 0) {
        std::cout << m << " ";
    }
}

void lagrange(int num) {
    if (num == 0) {
        std::cout << 0;
        return;
    }
    int i = sqrt(num);
    for (; i > 0; --i) {
        int i2 = i * i;
        int k = sqrt(num - i2);
        for (; k >= 0; --k) {
            int k2 = k * k;
            int l = sqrt(num - i2 - k2);
            for (; l >= 0; --l) {
                int l2 = l * l;
                int m = sqrt(num - i2 - k2 - l2);
                for (; m >= 0; --m) {
                    int m2 = m * m;
                    if (i2 + k2 + l2 + m2 == num) {
                        print(i, k, l, m);
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    lagrange(n);
}