//
// Created by Dashbah on 24.04.2023.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Guest {
    int id;
    std::string name;
    int dist;

    bool operator<(const Guest &other) const {
        return (dist < other.dist) || (dist == other.dist && name < other.name);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int m, n;
    std::cin >> n >> m;
    std::vector<Guest> guests(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> guests[i].id;
        getline(std::cin, guests[i].name);
    }
    std::vector<std::vector<int>> g(m);
    int first, last;
    for (int i = 0; i < m; ++i) {
        std::cin >> first;
        std::cin >> last;
        g[first].emplace_back(last);
        g[last].emplace_back(first);
    }

    int s;
    std::cin >> s;

    std::queue<int> q;
    q.push(s);
    std::vector<bool> used(n);
    std::vector<int> d(n), p(n);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : g[v]) {
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                guests[to].dist = guests[v].dist + 1;
                p[to] = v;
            }
        }
    }

    std::sort(guests.begin(), guests.end());

    for (auto &guest : guests) {
        std::cout << guest.name << "\n";
    }
    return 0;
}
