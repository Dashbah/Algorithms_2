//
// Created by Dashbah on 31.05.2023.
//


#include <iostream>
#include <vector>

bool isValid(std::vector<int> &num) {
    num[0] *= 2;
    if (num[0] > 9) {
        num[0] -= 9;
    }

    num[2] *= 2;
    if (num[2] > 9) {
        num[2] -= 9;
    }

    num[4] *= 2;
    if (num[4] > 9) {
        num[4] -= 9;
    }

    int res = 0;
    for (auto n : num) {
        res += n;
    }

    return res % 10 == 0;
}

int main() {
    std::string num;
    std::getline(std::cin, num);
    std::vector<int> vec;
    for (auto ch : num) {
        vec.push_back(ch - '0');
    }

    if (isValid(vec)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}