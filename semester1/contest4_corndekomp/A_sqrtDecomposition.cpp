//
// Created by Dashbah on 15.10.2022.
//
// TL91
#include <vector>
#include <iostream>
#include <cmath>

int zapros(int left, int right, std::vector<int> &vec, const std::vector<int> &vec1,
           const std::vector<int> &vec2, int length1, int length2) {
    int result = 0;
    --left;
    --right;
    int len1_len2 = length1 * length2;
    while (left <= right) {
        if (left % (len1_len2) == 0 && left + len1_len2 - 1 <= right) {
            result += vec2[left / len1_len2];
            left += len1_len2;
        } else {
            if (left % length1 == 0 && left + length1 - 1 <= right) {
                result += vec1[left / length1];
                left += length1;
            } else {
                if (vec[left++] == 0) {
                    ++result;
                }
            }
        }
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec;
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    std::vector<int> vec1;
    int size = ceil(sqrt(n));
    int length1 = ceil(n / (size * 1.0));
    vec1.resize(size);
    for (auto i = 0; i < n; ++i) {
        if (vec[i] == 0) {
            vec1[i / length1] += 1;
        }
    }

    std::vector<int> vec2;
    int size2 = ceil(sqrt(size));
    int length2 = ceil(size / (size2 * 1.0));
    vec2.resize(size2);
    for (auto i = 0; i < size; ++i) {
        vec2[i / length2] += vec1[i];
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int left, right;
        std::cin >> left >> right;
        std::cout << zapros(left, right, vec, vec1, vec2, length1, length2) << " ";
    }
}