//
// Created by Dashbah on 22.02.2023.
//
#include <iostream>
#include <vector>

int lenOfSequence(std::string first, std::string second) {
    std::vector<std::vector<int>> vec;
    for (size_t i = 0; i <= first.size(); ++i) {
        vec.emplace_back(std::vector<int>(second.size() + 1));
    }

    for (size_t i = 1; i <= first.size(); ++i) {
        for (size_t j = 1; j <= second.size(); ++j) {
            vec[i][j] = (first[i - 1] == second[j - 1]) ? (vec[i - 1][j - 1] + 1)
                                                        : std::max(vec[i - 1][j], vec[i][j - 1]);
        }
    }

    return vec.back().back();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string first, second;
    std::cin >> first >> second;

    std::cout << lenOfSequence(first, second) << std::endl;

    return 0;
}