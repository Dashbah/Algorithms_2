//
// Created by Dashbah on 13.02.2023.
// sourse: https://ru.algorithmica.org/cs/decomposition/scanline/
#include <iostream>
#include <vector>

struct Event {
    int x, type, idx;

    bool operator<(Event other) const {
        return (x < other.x || (x == other.x && type > other.type));
    }
};

void insertionSort(std::vector<Event> &vec) {
    for (size_t current = 0; current != vec.size(); ++current) {
        for (auto j = current; j != 0 && vec[j] < vec[j - 1]; --j) {
            auto val = vec[j - 1];
            vec[j - 1] = vec[j];
            vec[j] = val;
        }
    }
}

void scanLine() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Event> events;
    int left, right;
    for (int i = 0; i < n; ++i) {
        std::cin >> left >> right;
        events.push_back({left, 1});
        events.push_back({right, -1});
    }
    int point;
    for (int i = 0; i < m; ++i) {
        std::cin >> point;
        events.push_back({point, 0, i});
    }

    //    std::sort(events.begin(), events.end(), [](Event a, Event b) {
    //        return (a.x < b.x || (a.x == b.x && a.type > b.type));
    //    });
    insertionSort(events);

    std::vector<int> ans(m);
    int cnt = 0;
    for (auto event : events) {
        cnt += event.type;
        if (event.type == 0) {
            ans[event.idx] = cnt;
        }
    }
    for (auto val : ans) {
        std::cout << val << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    scanLine();

    return 0;
}