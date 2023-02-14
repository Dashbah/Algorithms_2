#include <iostream>
#include <deque>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums;
    // int elem;
    nums.resize(n);
    for (auto i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::deque<int> deque;
    for (auto i = 0; i < k; ++i) {
        while (!deque.empty()) {
            if (deque.back() > nums[i]) {
                deque.pop_back();
            } else {
                break;
            }
        }
        deque.push_back(nums[i]);
    }
    std::cout << deque.front() << " ";
    for (auto i = k; i < n; ++i) {
        while (!deque.empty()) {
            if (deque.back() > nums[i]) {
                deque.pop_back();
            } else {
                break;
            }
        }
        deque.push_back(nums[i]);
        if (deque.front() == nums[i - k]) {
            deque.pop_front();
        }
        std::cout << deque.front() << " ";
    }
}