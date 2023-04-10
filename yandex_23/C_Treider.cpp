#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    bool isMoney = true;
    // double money = 1;
    int n;
    std::cin >> n;
    int today;
    int tomorrow;
    std::cin >> tomorrow;

    std::vector<int> result;
    for (int i = 1; i < n; ++i) {
        today = tomorrow;
        std::cin >> tomorrow;
        if (isMoney && tomorrow > today) {
            // buy
            isMoney = false;
            // money /= today;
            result.emplace_back(i);
            continue;
        }
        if (!isMoney && tomorrow < today) {
            // sell
            isMoney = true;
            // money *= today;
            result.emplace_back(i);
            continue;
        }
    }

    if (!isMoney) {
        // today is tomorrow
        // money *= tomorrow;
        result.emplace_back(n);
    }

    // std::cout << "money: " << money << std::endl;
    std::cout << result.size() / 2 << std::endl;
    for (int i = 0; i < result.size(); i += 2) {
        std::cout << result[i] << " " << result[i + 1] << std::endl;
    }

    return 0;
}