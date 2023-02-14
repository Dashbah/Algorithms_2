#include <iostream>
#include <vector>
//
// Created by Dashbah on 18.10.2022.
//
// OK
int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec;
    std::vector<int> vec1;
    vec.resize(n);
    vec1.resize(n);
    int num;
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
        if (vec[i] == 0) {
            vec1[i] = ++zeros;
        } else {
            vec1[i] = zeros;
        }
    }

    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int left, right;
        std::cin >> left >> right;
        int result = vec1[right - 1] - vec1[left - 1];
        if (vec[left - 1] == 0) {
            ++result;
        }
        std::cout << result << " ";
    }
}
