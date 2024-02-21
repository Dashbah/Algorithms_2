//
// Created by Dashbah on 28.04.2023.
//
#include <vector>
#include <iostream>

int compress(std::string &chars) {
    if (chars.empty()) {
        return 0;
    }
    int curr = 0;
    int left = 0, right = 0;
    for (int i = 1; i < chars.size(); ++i) {
        if (chars[i] != chars[i - 1]) {
            right = i - 1;
            // add to result
            chars[curr++] = chars[i - 1];
            int numOfChars = right - left + 1;
            if (numOfChars > 1) {
                // add num to res
                if (numOfChars < 10) {
                    chars[curr++] = std::to_string(numOfChars)[0];
                } else {
                    auto numOfCharsString = std::to_string(numOfChars);
                    for (auto item: numOfCharsString) {
                        chars[curr++] = item;
                    }
                }
            }
            left = i;
        }
    }

    // add last char to result
    chars[curr++] = chars.back();
    int numOfChars = chars.size() - left;
    if (numOfChars > 1) {
        // add num to res
        auto numOfCharsString = std::to_string(numOfChars);
        for (auto item: numOfCharsString) {
            chars[curr++] = item;
        }
    }

    return curr;
}

int main() {
    std::string first = "aaaaaaaaaaaaaaaaaaaaassww";
    auto n = compress(first);

    for (int i = 0; i < n; ++i) {
        std::cout << first[i];
    }
}