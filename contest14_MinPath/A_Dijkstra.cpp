//
// Created by Dashbah on 26.05.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

const int64_t kInf = 1e18;

void dijkstra(std::vector<std::vector<std::pair<int64_t, int64_t>>> &graph,
              std::vector<int64_t> &distance, std::vector<bool> &used, std::vector<int64_t> &parent,
              std::set<std::pair<int64_t, int64_t>> &st) {
    while (!st.empty()) {
        int64_t v = st.begin()->second;
        st.erase({distance[v], v});
        used[v] = true;
        for (const auto &[neighbour, len] : graph[v]) {
            if (distance[v] + len < distance[neighbour]) {
                st.erase({distance[neighbour], neighbour});
                distance[neighbour] = distance[v] + len;
                st.insert({distance[neighbour], neighbour});
                parent[neighbour] = v;
            }
        }
    }
}

int main() {
    int64_t n, k, start;
    std::cin >> n >> k;
    std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(n + 1);
    std::set<std::pair<int64_t, int64_t>> st;
    for (int64_t i = 0; i < k; ++i) {
        int64_t from, to, len;
        std::cin >> from >> to >> len;
        graph[from].push_back(std::make_pair(to, len));
    }
    start = 0;
    std::vector<int64_t> distance(n + 1, kInf);
    std::vector<int64_t> parent(n + 1);
    std::vector<bool> used(n + 1);
    st.insert({0, start});
    distance[start] = 0;
    dijkstra(graph, distance, used, parent, st);
    for (int i = 1; i < n; ++i) {
        std::cout << distance[i] << std::endl;
    }
    return 0;
}