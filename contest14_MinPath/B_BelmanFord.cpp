//
// Created by Dashbah on 26.05.2023.
//
#include <iostream>
#include <vector>

const int64_t kInf = 500 * (1e9) + 1;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int64_t>> graph(n, std::vector<int64_t>(n, kInf));
    int f, t, weight;
    for (int i = 0; i < m; ++i) {
        std::cin >> f >> t >> weight;
        graph[f][t] = weight;
    }
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                graph[from][to] = std::min(graph[from][to], graph[from][k] + graph[k][to]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (graph[i][j] == kInf) {
                    graph[i][j] = -1;
                }
                std::cout << i << " " << j << " " << graph[i][j] << std::endl;
            }
        }
    }

    return 0;
}