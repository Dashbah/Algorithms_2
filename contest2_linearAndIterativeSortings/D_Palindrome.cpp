//
// Created by Dashbah on 27.01.2023.
//
#include <iostream>
#include <vector>
#include <queue>

std::deque<char> countingSortNotStable(std::vector<char>& vec) {
    int k = 'Z' - 'A' + 1;
    std::vector<int> b(k);
    for (auto letter : vec) {
        ++b[letter - 'A'];
    }
    std::deque<char> deque;

    for (int i = 0; i < k; ++i) {
        if (b[i] % 2 != 0) {
            deque.push_front(i + 'A');
            --b[i];
            break;
        }
    }
    for (int i = k - 1; i >= 0; --i) {
        while (b[i] >= 2) {
            deque.push_back(i + 'A');
            deque.push_front(i + 'A');
            b[i] -= 2;
        }
    }

    return deque;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<char> vec(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    auto result = countingSortNotStable(vec);

    while (!result.empty()) {
        std::cout << result.front();
        result.pop_front();
    }
}