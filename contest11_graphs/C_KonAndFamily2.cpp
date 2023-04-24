//
// Created by Dashbah on 24.04.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

struct Guest {
    int id;
    std::string name;
    int dist;
    bool used = false;

    bool operator<(const Guest &other) const {
        return (dist < other.dist) || (dist == other.dist && name < other.name);
    }
};

void dfs(int v, std::vector<Guest> &guests, const std::vector<std::vector<Guest>> &g) {
    guests[v].used = true;
    std::cout << guests[v].name << "\n";
    for (auto &i : g[v]) {
        if (!guests[i.id].used) {
            // guests[i.id].dist = guests[v].dist + 1;
            dfs(i.id, guests, g);
        }
    }
}

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
    std::vector<std::vector<Guest>> g(m);
    int first, last;
    for (int i = 0; i < m; ++i) {
        std::cin >> first;
        std::cin >> last;
        g[first].emplace_back(guests[last]);
        g[last].emplace_back(guests[first]);
    }

    for (int i = 0; i < m; ++i) {
        std::sort(g[i].begin(), g[i].end());
    }

    int s;
    std::cin >> s;

    dfs(s, guests, g);

    return 0;
}
