#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    std::vector<std::vector<char>> glass(n, std::vector<char>(m));
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            glass[i][j] = getchar();
        }
        getchar();
    }

    int k;
    cin >> k;

    std::string string;
    int num;
    char smth;

    int fullLayer = n - 1;
    for (int i = 0; i < k; ++i) {
        std::cin >> string;
        std::cin >> num;
        std::cin >> smth;

        for (int nLayer = 0; nLayer < num; ++nLayer) {
            for (auto &elem: glass[fullLayer - nLayer - 1]) {
                if (elem == ' ') {
                    elem = smth;
                }
            }
        }
        fullLayer -= num;
    }

    for (const auto& row: glass) {
        for (auto elem: row) {
            std::cout << elem;
        }
        std::cout << "\n";
    }

    return 0;
}