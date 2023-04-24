//
// Created by Dashbah on 24.04.2023.
//
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>

struct Building {
    int id;
    int dist;
    int map_id;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, k;
    std::cin >> n >> k;

    std::vector<std::unordered_map<int, std::list<int>>> adj_list(n, std::unordered_map<int, std::list<int>>());
    int r, left, right;
    for (int cart_id = 1; cart_id <= k; ++cart_id) {
        std::cin >> r;
        for (int j = 0; j < r; ++j) {
            std::cin >> left >> right;
            adj_list[left - 1][right - 1].emplace_back(cart_id);
            adj_list[right - 1][left - 1].emplace_back(cart_id);
        }
    }

    int s = 0;
    std::queue<int> q;  // Очередь вершин
    q.push(s);     // Добавляем стартовую вершину
    std::vector<bool> used(n);   // Вектор признака посещенности вершин
    std::vector<int> d(n), p(n), maps(n); // Векторы расстояний и предков
    used[s] = true; // Стартовую вершину считаем посещенной
    p[s] = -1;      // У стартовой вершины нет предка
    maps[s] = 0;
    while (!q.empty()) {
        int v = q.front();   // Извлекаем из головы очереди веришну
        q.pop();             // Удаляем извлеченную вершину
        for (auto &to: adj_list[v]) // Просмотр всех смежных вершин
        {
            if (!used[to.first])   // Если вершина не посещена,
            {
                used[to.first] = true;  // посещаем ее
                q.push(to.first);       // и добавляем к концу очереди
                d[to.first] = d[v] + 1; // Считаем расстояние до вершины
                p[to.first] = v;        // Запоминаем предка
                // maps[to.first] = (maps[v] == to.second) ?
            }
        }
    }


//    // начинаем поиск в ширину
//    std::queue<Building> q;
//    std::unordered_map<int, int> visited;
//
//    int s = 0;
//    int t = n - 1;
//    q.push({s, 0});
//    visited[s] = 0;
//
//    while (!q.empty()) {
//        Building curr = q.front();
//        q.pop();
//
//        if (curr.id == t) {
//            std::cout << curr.dist << std::endl;
//            return 0;
//        }
//
//        for (auto neighbor : adj_list[curr.id]) {
//            int neighbor_id = neighbor.first;
//            int neighbor_dist = neighbor.second;
//
//            if (visited.find(neighbor_id) == visited.end() || visited[neighbor_id] > curr.dist + neighbor_dist) {
//                visited[neighbor_id] = curr.dist + neighbor_dist;
//                q.push({neighbor_id, visited[neighbor_id]});
//            }
//        }
//    }

    return 0;
}
