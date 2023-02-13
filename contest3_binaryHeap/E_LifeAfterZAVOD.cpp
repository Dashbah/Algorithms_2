//
// Created by Dashbah on 07.02.2023.
//
#include <iostream>
#include <vector>

struct Interval {
    int left;
    int right;

    Interval() = default;

    Interval(int left, int right) : left(left), right(right) {
    }
};

int getRequest() {
    char command;
    std::cin >> command;
    if (command == '!') {
        return -1;
    }
    getchar();
    int time;
    std::cin >> time;
    return time;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    int min = 2147483647;
    int max = 0;
    std::vector<Interval> intervals(n);
    int left, right;
    for (int i = 0; i < n; ++i) {
        std::cin >> left >> right;
        if (left < min) {
            min = left;
        }
        if (right > max) {
            max = right;
        }
        intervals[i] = Interval(left, right);
    }
    std::vector<int> chats(max - min + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = intervals[i].left - min; j <= intervals[i].right - min; ++j) {
            ++chats[j];
        }
    }

    int time_command;
    do {
        time_command = getRequest();
        if (time_command == -1) {
            break;
        }
        std::cout << "! " << chats[time_command - min] << std::endl;
    } while (true);
}