//
// Created by Dashbah on 17.04.2023.
//
#include <iostream>
#include <list>
#include <map>

// the source: https://youtu.be/1KzUikIae6k

std::list<int> encode(const std::string &string) {
    int dict_size = 128;
    std::map<std::string, int> dictionary;
    for (int i = 0; i < dict_size; ++i) {
        // std::string(reinterpret_cast<const char *>(static_cast<char>(i)));
        dictionary[std::string(1, static_cast<char>(i))] = i;
    }

    std::string found_chars;
    std::list<int> result;
    for (auto character : string) {
        std::string chars_to_add = found_chars + character;
        if (dictionary.find(chars_to_add) != dictionary.end()) {
            found_chars = chars_to_add;
        } else {
            result.emplace_back(dictionary[found_chars]);
            dictionary[chars_to_add] = dict_size++;
            found_chars = std::string(1, character);
        }
    }
    if (!found_chars.empty()) {
        result.emplace_back(dictionary[found_chars]);
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string input;
    getline(std::cin, input);
    auto result = encode(input);
    std::cout << result.size() << std::endl;
    for (auto symbol_num : result) {
        std::cout << symbol_num << " ";
    }
    return 0;
}
