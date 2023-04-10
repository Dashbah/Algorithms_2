//
// Created by Dashbah on 09.04.2023.
//
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i];
    }

    if (n < 2) {
        std::cout << 0;
        return 0;
    }


    for (int i = 1; i < n; ++i) {
        if (input[i] > input[i - 1]) {
            break;
        }
        if (i == n - 1) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    std::vector<std::pair<int, int>> left_max(n);
    std::vector<std::pair<int, int>> right_max(n);

    // check for < 2 and so on

    // denom / numer
    int leftMin = 0;
    // double leftMax = input[1] / input[0];
    if (input[1] < input[leftMin]) {
        leftMin = 1;
    }
    left_max[1] = {0, 1};
    for (int i = 2; i < n; ++i) {
        left_max[i] = (input[i] * 1.0 / input[leftMin] >
                       input[left_max[i - 1].second] * 1.0 / input[left_max[i - 1].first]) ?
                      std::pair<int, int>(leftMin, i) : left_max[i - 1];
        if (input[i] < input[leftMin]) {
            leftMin = i;
        }
    }

    //  denom / num
    int rightMax = n - 1;
    // double leftMax = input[1] / input[0];
    if (input[n - 2] > input[rightMax]) {
        rightMax = n - 2;
    }
    right_max[n - 2] = {n - 2, n - 1};
    for (int i = n - 3; i >= 0; --i) {
        right_max[i] = (input[rightMax] * 1.0 / input[i] >
                        input[right_max[i + 1].second] * 1.0 / input[right_max[i + 1].first]) ?
                       std::pair<int, int>(i, rightMax) : right_max[i + 1];
        if (input[i] > input[rightMax]) {
            rightMax = i;
        }
    }

    double maxProizv = 1.0 / input[right_max[0].first] * input[right_max[0].second];
    int resInd = 0;
    for (int i = 1; i < n - 1; ++i) {
        double currentProizv = 1.0 * input[left_max[i].second] / input[left_max[i].first]
                               / input[right_max[i].first] * input[right_max[i].second];
        if (currentProizv > maxProizv) {
            maxProizv = currentProizv;
            resInd = i;
        }
    }
    double temp = 1.0 * input[left_max[1].first] / input[left_max[1].second];
    if (temp > maxProizv) {
        maxProizv = temp;
        resInd = n - 1;
    }

    if (resInd == 0) {
        std::cout << 1 << std::endl;
        std::cout << right_max[resInd].first + 1 << " " << right_max[resInd].second + 1 << std::endl;
        return  0;
    }
    if (resInd == n - 1) {
        std::cout << 1 << std::endl;
        std::cout << left_max[resInd].first + 1 << " " << left_max[resInd].second + 1 << std::endl;
        return  0;
    }

    if (left_max[resInd].first == right_max[resInd].second && left_max[resInd].second == right_max[resInd].first) {
        std::cout << 1 << std::endl;
        std::cout << right_max[resInd].first + 1 << " " << right_max[resInd].second + 1;
        return 0;
    }

    std::cout << 2 << std::endl;
    std::cout << left_max[resInd].first + 1 << " " << left_max[resInd].second + 1 << std::endl;
    std::cout << right_max[resInd].first + 1 << " " << right_max[resInd].second + 1 << std::endl;

//    if (
////            (input[left_max[resInd].first] == input[left_max[resInd].second]) ||
////        (input[right_max[resInd].first] == input[right_max[resInd].second]) ||
//        left_max[resInd].first == right_max[resInd].second && left_max[resInd].second == right_max[resInd].first) {
//        std::cout << 1 << std::endl;
//        std::cout << right_max[resInd].first + 1 << " " << right_max[resInd].second + 1;
//    } else {
//        std::cout << 2 << std::endl;
//        std::cout << left_max[resInd].first + 1 << " " << left_max[resInd].second + 1 << std::endl;
//        std::cout << right_max[resInd].first + 1 << " " << right_max[resInd].second + 1 << std::endl;
//    }

    return 0;
}