#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> keys(n);
    std::map<int, int> keyboard;
    for (int i = 0; i < n; ++i) {
        std::cin >> keys[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> keyboard[keys[i]];
    }

    int len;
    std::cin >> len;

    if (len == 0) {
        std::cout << 0;
    }

    int64_t result = 0;
    int previous;
    std::cin >> previous;
    int current;
    for (int i = 1; i < len; ++i) {
        std::cin >> current;
        if (std::abs(keyboard[previous] - keyboard[current]) != 0) {
            ++result;
        }
        previous = current;
    }

    std:: cout << result;
    return 0;
}