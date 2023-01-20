//
// Created by Dashbah on 19.01.2023.
//
#include <iostream>

int getSecondMax(int left, int right) {
    if (left == right) {
        return -1;
    }
    std::cout << "? " << left << " " << right << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void eMax() {
    int left = 1;
    int right;
    std::cin >> right;
    int second_max;
    while (left < right) {
        second_max = getSecondMax(left, right);
        if (second_max == left) {
            ++left;
            continue;
        }
        if (second_max == right) {
            --right;
            continue;
        }

        int left_second_max = getSecondMax(left, second_max);
        if (second_max == left_second_max) {
            // second_max = left_second_max;
            right = second_max - 1;
        } else {
            // int right_second_max = getSecondMax(second_max, right);
            // second_max = right_second_max;
            left = second_max + 1;
        }

    }

    int res;
    if (left == second_max) {
        res = right;
    } else {
        res = left;
    }
    std::cout << "! " << res << std::endl;
}

int main() {
    eMax();
}