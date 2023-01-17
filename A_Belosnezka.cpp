//
// Created by Dashbah on 17.01.2023.
//

#include <utility>
#include <iostream>

std::pair<int, int> firstSecMax() {
    int input;
    int max_height = 0;
    int second_max_height = 0;
    do {
        std::cin >> input;
        if (input > second_max_height) {
            if (input > max_height) {
                second_max_height = max_height;
                max_height = input;
            } else {
                second_max_height = input;
            }
        }
    } while (input != 0);
    return {max_height, second_max_height};
    std::cout << max_height << std::endl;
    std::cout << second_max_height << std::endl;
}