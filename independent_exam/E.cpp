//
// Created by Dashbah on 31.05.2023.
//
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>

struct Rock {
    int id;
    int width;

    Rock(int id, int width) : id(id), width(width) {}

};

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, w;
    std::cin >> n >> w;
    int a, wi;
    std::unordered_map<int, std::list<std::pair<int, int>>> map;

    for (int i = 1; i <= n; ++i) {
        std::cin >> a >> wi;
        map[a].emplace_back(std::pair(i, wi));
    }

    int rocksLeft = n;
    std::vector<int> res(n);
    int height = 0, width;
    while (rocksLeft > 0) {
        for(auto it = map.begin(); it != map.end(); ++it) {
            if (!it->second.empty()) {
                res[n - rocksLeft] = it->second.back().first;
                width = map[i].back().second;
                map[i].pop_back();
                i += width;
                --rocksLeft;
            } else {
                ++i;
            }
        }
//        for (int i = 1; i <= w;) {
//
//        }
        ++height;
    }

    std::cout << height << std::endl;

    for (int &id : res) {
        std::cout << id << " ";
    }

}