//
// Created by Dashbah on 19.01.2023.
//

#include <iostream>
#include <vector>

/**
 *
 * @param vec
 * @return value of max element of the array
 */
int maxElement(const std::vector<int> &vec) {
    int max = -1;
    for (auto elem : vec) {
        if (elem > max) {
            max = elem;
        }
    }
    return max;
}

int numOfWires(const std::vector<int> &vec, int length) {
    int res = 0;
    for (auto elem : vec) {
        res += elem / length;
    }
    return res;
}

int findLength(const std::vector<int> &vec, int k) {
    int left = 0;
    int right = maxElement(vec) + 1;
    int mid;
    int res = 0;
    while (right - left > 1) {
        mid = (left + right) / 2;
        int num_of_wires = numOfWires(vec, mid);
        if (num_of_wires >= k) {
            res = mid;
            left = mid;
        } else {
            right = mid;
        }
    }

    return res;
}

void dLenght() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> lengths(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lengths[i];
    }

    int res = findLength(lengths, k);
    std::cout << res << std::endl;
}

//int main() {
//    dLenght();
//}