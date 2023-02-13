//
// Created by Dashbah on 14.02.2023.
// the source: https://e-maxx.ru/algo/maximum_average_segment
// algorithm by Jay Kadane

#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    int ans_left_idx = 0, ans_right_idx = 0;
    int sum = 0;
    int minus_pos = -1;

    int ans;
    std::cin >> ans;
    sum += ans;
    if (sum > ans) {
        ans = sum;
        ans_left_idx = minus_pos + 1;
        ans_right_idx = 0;
    }
    if (sum < 0) {
        sum = 0;
        minus_pos = 0;
    }

    int elem;
    for (int i = 1; i < n; ++i) {
        std::cin >> elem;
        sum += elem;
        if (sum > ans) {
            ans = sum;
            ans_left_idx = minus_pos + 1;
            ans_right_idx = i;
        }
        if (sum < 0) {
            sum = 0;
            minus_pos = i;
        }
    }

    std::cout << ans_left_idx << " " << ans_right_idx;

    return 0;
}