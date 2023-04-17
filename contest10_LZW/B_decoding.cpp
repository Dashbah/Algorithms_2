//
// Created by Dashbah on 17.04.2023.
//
#include <iostream>
#include <list>
#include <map>

// the source: https://youtu.be/1KzUikIae6k

std::string encode(std::list<int> &encoded_text) {
    int dict_size = 128;
    std::map<int, std::string> dictionary;
    for (int i = 0; i < dict_size; ++i) {
        dictionary[i] = std::string(1, static_cast<char>(i));
    }

    std::string characters = std::string(1, static_cast<char>(*encoded_text.begin()));
    encoded_text.pop_front();
    std::string result = {characters[0]};
    for (auto code : encoded_text) {
        std::string entry = (dictionary.find(code) != dictionary.end())
                                ? dictionary[code]
                                : characters + characters[0];
        result += entry;
        dictionary[dict_size++] = characters + entry[0];
        characters = entry;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::list<int> input;
    int code;
    for (int i = 0; i < n; ++i) {
        std::cin >> code;
        input.emplace_back(code);
    }
    std::cout << encode(input);
    return 0;
}
