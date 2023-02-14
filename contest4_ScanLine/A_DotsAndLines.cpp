//
// Created by Dashbah on 13.02.2023.
// sourse: https://ru.algorithmica.org/cs/decomposition/scanline/
// quick sort: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
#include <iostream>
#include <vector>
#include <iterator>

struct Event {
    int x, type, idx;

    bool operator<(Event other) const {
        return (x < other.x || (x == other.x && type > other.type));
    }

    bool operator<=(Event other) const {
        return (*this < other) || (x == other.x && type == other.type);
    }
};

template <typename ValueType>
int partition(std::vector<ValueType> &vec, int start, int end) {
    ValueType pivot = vec[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (vec[i] <= pivot) {
            count++;
        }
    }

    // Giving pivot element its correct position
    int pivot_index = start + count;
    std::swap(vec[pivot_index], vec[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivot_index && j > pivot_index) {
        while (vec[i] <= pivot) {
            i++;
        }
        while (pivot < vec[j]) {
            j--;
        }
        if (i < pivot_index && j > pivot_index) {
            std::swap(vec[i++], vec[j--]);
        }
    }

    return pivot_index;
}

template <typename ValueType>
void quickSort(std::vector<ValueType> &vec, int start, int end) {
    // base case
    if (start >= end) {
        return;
    }

    // partitioning the array
    int p = partition(vec, start, end);

    // Sorting the left part
    quickSort(vec, start, p - 1);

    // Sorting the right part
    quickSort(vec, p + 1, end);
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
    quickSort(events, 0, static_cast<int>(events.size()) - 1);

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