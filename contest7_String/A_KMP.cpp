//
// Created by Dashbah on 20.03.2023.
//
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string text;
    std::string substr;
    std::getline(std::cin, substr);
    std::getline(std::cin, text);

    std::vector<int> br(substr.size());
    br[0] = 0;
    for (size_t i = 1; i <= substr.size(); ++i) {
        for (size_t j = 1; j < i; ++j) {
            bool equals = true;
            for (size_t k = 0; k < j; ++k) {
                if (substr[k] != substr[i - j + k]) {
                    equals = false;
                }
            }
            if (equals) {
                br[i - 1] = j;
            }
        }
    }

    std::vector<int> brs(substr.size());
    brs[0] = 0;
    for (size_t i = 1; i <= substr.size(); ++i) {
        if (i == substr.size() || substr[br[i]] != substr[i]) {
            brs[i - 1] = br[i - 1];
        } else {
            brs[i - 1] = brs[br[i - 1]];
        }
    }

    std::vector<int> result(text.size());

    std::vector<int> res;

    size_t kol = 0;

    for (size_t i = 0; i < text.size(); ++i) {
        while (kol > 0 && substr[kol] != text[i]) {
            kol = brs[kol - 1];
        }
        if (substr[kol] == text[i]) {
            kol += 1;
        }
        if (kol == substr.size()) {
            res.push_back(i - substr.size() + 1);
            kol = brs[kol - 1];
        }
    }

    std::cout << res.size() << "\n";
    for (int re : res) {
        std::cout << re << "\n";
    }

    return 0;
}

