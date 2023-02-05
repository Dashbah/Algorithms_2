#include <iostream>
#include <vector>

//
// Created by Dashbah on 04.02.2023.
//
int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    int value;
    int res = n - 1;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        vec[i] = value;
        int parent = (i - 1) / 2;
        if (vec[parent] < vec[i]) {
            res = i - 1;
            break;
        }
    }
    std::cout << res << std::endl;
}