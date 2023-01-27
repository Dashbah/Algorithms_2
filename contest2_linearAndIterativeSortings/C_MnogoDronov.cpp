//
// Created by Dashbah on 26.01.2023.
//
#include <iostream>
#include <vector>

struct Drone {
    int id;
    int value;
    unsigned char bytes[4];

    Drone() {
    }

    Drone(int id, int number) : id(id), value(number) {
        bytes[0] = (number & 0x000000FF);
        bytes[1] = (number & 0x0000FF00) >> 8;
        bytes[2] = (number & 0x00FF0000) >> 16;
        bytes[3] = (number & 0xFF000000) >> 24;
    }
    ~Drone() {
    }
};

std::vector<Drone> countingSort(const std::vector<Drone> &vec, int place, int min = 0,
                                int max = 255) {
    int k = max - min + 1;
    std::vector<int> b(k);
    for (auto &number : vec) {
        ++b[number.bytes[place]];
    }
    // array of partial sums
    for (int i = 1; i < k; ++i) {
        b[i] = b[i - 1] + b[i];
    }

    std::vector<Drone> result(vec.size());
    for (int i = vec.size() - 1; i >= 0; --i) {
        result[--b[vec[i].bytes[place] - min]] = vec[i];
    }
    return result;
}

void digitalSorting(const std::vector<Drone> &vec, std::vector<Drone> &result) {
    result = vec;
    for (int i = 0; i < 4; ++i) {
        result = countingSort(result, i);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Drone> vec(n);
    int id;
    int value;
    for (int i = n - 1; i >= 0; --i) {
        std::cin >> id;
        std::cin >> value;
        vec[i] = Drone(id, value);
    }

    std::vector<Drone> result;
    digitalSorting(vec, result);

    for (int i = n - 1; i >= 0; --i) {
        std::cout << result[i].id << "\t" << result[i].value << std::endl;
    }
}