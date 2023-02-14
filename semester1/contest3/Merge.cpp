//
// Created by Dashbah on 04.10.2022.
//
#include <list>
#include <iostream>

using std::list;

list<int> merge(const list<int> &first, const list<int> &second) {
    list<int> result;
    auto cur_first = first.begin();
    auto cur_second = second.begin();
    size_t position = 0;
    while (cur_first != first.end() && cur_second != second.end()) {
        if (*cur_first < *cur_second) {
            result.emplace_back(*(cur_first++));
        } else {
            result.emplace_back(*(cur_second++));
        }
        ++position;
    }
    if (cur_first != first.end()) {
        for (auto i = cur_first; i != first.end(); ++i) {
            result.emplace_back(*(cur_first++));
        }
    } else {
        for (auto i = cur_second; i != second.end(); ++i) {
            result.emplace_back(*(cur_second++));
        }
    }
    return result;
}

//int main() {
//    int n, m;
//    std::cin >> n >> m;
//
//    list<int> l1;
//    list<int> l2;
//    int val;
//    for (auto i = 0; i < n; ++i) {
//        std::cin >> val;
//        l1.emplace_back(val);
//    }
//    for (auto i = 0; i < m; ++i) {
//        std::cin >> val;
//        l2.emplace_back(val);
//    }
//    for (auto i : merge(l1, l2)) {
//        std::cout << i << " ";
//    }
//}