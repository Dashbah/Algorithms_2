//
// Created by Dashbah on 18.01.2023.
//

#include <iostream>
#include <valarray>

/**
 * finds solution for x^2 + squareRoot(x) = c
 * @param c
 */

double func(double c) {
    double accuracy = 0.0000001;
    double left = 0;
    double right = std::sqrt(c);
    double mid;
    while (right - left > accuracy) {
        mid = (right + left) / 2;
        double val = mid * mid + std::sqrt(mid);
        if (val - c > 0) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return mid;
}

//int main() {
//    double c;
//    std::cin >> c;
//    std::cout << std::fixed;
//    std::cout.precision(6);
//    std::cout << func(c);
//}