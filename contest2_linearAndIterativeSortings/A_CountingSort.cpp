//
// Created by Dashbah on 25.01.2023.
//
#include <vector>
#include <iostream>

std::vector<int> countingSort(const std::vector<int> &vec, int min, int max) {
    int k = max - min + 1;
    std::vector<int> b(k);
    for (auto value : vec) {
        ++b[value - min];
    }
    // array of partial sums
    for (int i = 1; i < k; ++i) {
        b[i] = b[i - 1] + b[i];
    }
    std::vector<int> result(vec.size());
    for (int i = vec.size() - 1; i >= 0; --i) {
        result[--b[vec[i] - min]] = vec[i];
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        return 0;
    }
    std::vector<int> vec(n);
    int min;
    int max;
    std::cin >> vec[0];
    min = max = vec[0];
    for (int i = 1; i < n; ++i) {
        std::cin >> vec[i];
        if (vec[i] < min) {
            min = vec[i];
        } else {
            if (vec[i] > max) {
                max = vec[i];
            }
        }
    }

    auto result = countingSort(vec, min, max);

    for (auto elem : result) {
        std::cout << elem << ' ';
    }
}