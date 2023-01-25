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
    int n;
    std::cin >> n;
    right = n;
    int second_max = getSecondMax(left, right);;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
//        if (left + 1 == right) {
//            break;
//        }
        int left_second_max = getSecondMax(left, mid);
        if (second_max == left_second_max) {
            right = mid;
            if (left + 1 == right) {
                break;
            }
        } else {
            left = mid;
            if (left + 1 == right) {
                break;
            }
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