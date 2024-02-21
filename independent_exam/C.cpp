//
// Created by Dashbah on 31.05.2023.
//
#include <vector>
#include <iostream>

class SumPlusPlus {
public:
    std::vector<int64_t> vec;

    void push(int64_t x) {
        vec.push_back(x);
    }

    void pop() {
        vec.pop_back();
    }

    void sum(int i, int k) {
        int64_t sum = 0;
        for (int first = i; first < i + k; ++first) {
            sum += vec[first];
        }
        vec.push_back(sum);
    }
};

int main() {
    int n;
    std::cin >> n;
    std::string command;
    SumPlusPlus sumPlusPlus = SumPlusPlus();
    for (int i = 0; i < n; ++i) {
        std::cin >> command;
        if (command == "pop") {
            sumPlusPlus.pop();
            continue;
        }
        if (command == "push") {
            int64_t num;
            std::cin >> num;
            sumPlusPlus.push(num);
            continue;
        }
        if (command == "sum") {
            int first, k;
            std::cin >> first >> k;
            sumPlusPlus.sum(first, k);
            continue;
        }
        if (command == "print") {
            for (auto &sym : sumPlusPlus.vec) {
                std::cout << sym << " ";
            }
            std::cout << std::endl;
            continue;
        }
    }
}