//
// Created by Dashbah on 18.01.2023.
//

#include <iostream>
#include <valarray>

/**
 * finds solution for x^2 + squareRoot(x) = c
 * @param c
 */

double accuracy = 0.0000001;

double func(double c) {
    double left = 0;
    double right = std::sqrt(c);
    while (left <= right) {
        double mid = left + (right - left) / 2;
        double val = mid * mid + std::sqrt(mid);
        double difference = (val - c) > 0 ? val - c : c - val;
        if (difference < accuracy) {
            return mid;
        } else {
            if (val > c) {
                right = mid;
            } else {
                left = mid;
            }
        }
    }
}

int main() {
    double c;
    std::cin >> c;
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << func(c);
}