#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int kMaxN = 301;
const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int n, x1, y1, x2, y2;
int dist[kMaxN][kMaxN];

bool isValid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int bfs() {
    memset(dist, -1, sizeof(dist));  // set all distances to -1 (unreachable)
    std::queue<std::pair<int, int>> q;
    q.push({x1, y1});
    dist[x1][y1] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == x2 && y == y2) {
            return dist[x2][y2];
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;  // unreachable
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    std::cout << bfs() << '\n';

    // Print the path
    if (dist[x2][y2] != -1) {
        std::vector<std::pair<int, int>> path;
        path.emplace_back(x2, y2);

        int x = x2;
        int y = y2;

        while (x != x1 || y != y1) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny) && dist[nx][ny] == dist[x][y] - 1) {
                    x = nx;
                    y = ny;
                    path.emplace_back(x, y);
                    break;
                }
            }
        }

        std::cout << x1 << ' ' << y1 << '\n';
        for (int i = static_cast<int>(path.size()) - 2; i >= 0; --i) {
            std::cout << path[i].first << ' ' << path[i].second << '\n';
        }
    }

    return 0;
}
