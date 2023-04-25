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
        return name < other.name;
    }

    bool operator==(const Guest &other) const {
        return name == other.name;
    }
};

std::vector<Guest> guests;

int comp(const void *left, const void *right) {
    int a = *reinterpret_cast<const int *>(left);
    int b = *reinterpret_cast<const int *>(right);
    if (guests[a] < guests[b]) {
        return -1;
    }
    if (guests[a] == guests[b]) {
        return 0;
    }
    return 1;
}

void sortLine(std::vector<int> &vector, const std::vector<Guest> &guests1) {
    for (size_t current = 1; current < vector.size(); ++current) {
        for (auto j = current; j > 0 && guests1[vector[j]] < guests1[vector[j - 1]]; --j) {
            std::swap(vector[j], vector[j - 1]);
        }
    }
}

void dfs(int v, const std::vector<std::vector<int>> &g) {
    guests[v].used = true;
    std::cout << guests[v].name << "\n";
    for (auto &i : g[v]) {
        if (!guests[i].used) {
            dfs(i, g);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int m, n;
    std::cin >> n >> m;
    guests = std::vector<Guest>(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> guests[i].id;
        getline(std::cin, guests[i].name);
    }
    std::vector<std::vector<int>> g(n);
    int first, last;
    for (int i = 0; i < m; ++i) {
        std::cin >> first;
        std::cin >> last;
        g[first].emplace_back(last);
        g[last].emplace_back(first);
    }

    for (int i = 0; i < n; ++i) {
        // sortLine(g[i], guests);
        if (!g[i].empty()) {
            qsort(&g[i][0], g[i].size(), sizeof(int), comp);
        }
    }

    int s;
    std::cin >> s;

    dfs(s, g);

    return 0;
}
