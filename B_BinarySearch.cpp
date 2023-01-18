//
// Created by Dashbah on 17.01.2023.
//

#include <vector>
#include <iostream>

int leftBinSearch(const std::vector<int> &vec, int elem) {
    if (vec.empty()) {
        return -1;
    }
    int ans = -1;
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left + 1) / 2;
        int mid_val = vec[mid];

        if (mid_val < elem) {
            left = mid + 1;
        } else if (mid_val > elem) {
            right = mid - 1;
        } else if (mid_val == elem) {
            ans = mid;
            right = mid - 1;
        }
    }

    return ans;
}

int rightBinSearch(const std::vector<int> &vec, int elem) {
    if (vec.empty()) {
        return -1;
    }
    int ans = -1;
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left + 1) / 2;
        int mid_val = vec[mid];

        if (mid_val < elem) {
            left = mid + 1;
        } else if (mid_val > elem) {
            right = mid - 1;
        } else if (mid_val == elem) {
            ans = mid;
            left = mid + 1;
        }
    }

    return ans;
}

void leftRightSearch() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    int elem;
    for (int i = 0; i < m; ++i) {
        std::cin >> elem;
        int left = leftBinSearch(vec, elem);
        if (left == -1) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << left + 1 << " ";
            std::cout << rightBinSearch(vec, elem) + 1 << std::endl;
        }
    }
}