//
// Created by Dashbah on 14.02.2023.
//
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<int64_t>> vec(n);

    vec[0] = std::vector<int64_t>(m);
    std::cin >> vec[0][0];
    for (int i = 1; i < m; ++i) {
        std::cin >> vec[0][i];
        vec[0][i] += vec[0][i - 1];
    }
    for (int i = 1; i < n; ++i) {
        vec[i] = std::vector<int64_t>(m);
        std::cin >> vec[i][0];
        vec[i][0] += vec[i - 1][0];
        for (int j = 1; j < m; ++j) {
            std::cin >> vec[i][j];
            vec[i][j] += vec[i - 1][j] + vec[i][j - 1] - vec[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;
    int64_t res;
    for (int i = 0; i < q; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        res = vec[x2 - 1][y2 - 1] - (x1 - 1 ? vec[x1 - 2][y2 - 1] : 0) -
              (y1 - 1 ? vec[x2 - 1][y1 - 2] : 0) + (x1 - 1 && y1 - 1 ? vec[x1 - 2][y1 - 2] : 0);
        std::cout << res << std::endl;
    }
    return 0;
}