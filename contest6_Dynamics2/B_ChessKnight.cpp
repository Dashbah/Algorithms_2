//
// Created by Dashbah on 11.03.2023.
//
// https://vk.com/@unilecs-task-106-hod-konya

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int64_t>> vec(n + 3, std::vector<int64_t>(m + 3, 0));

    vec[2][2] = 1;

    int start_i = 2, start_j = 2;
    while ((start_i < n + 1) || (start_j < m + 1)) {
        if (start_j == m + 1) {
            ++start_i;
        } else {
            ++start_j;
        }

        int i = start_i;
        int j = start_j;
        while ((i <= n + 1) && j >= 2) {
            vec[i][j] =
                vec[i + 1][j - 2] + vec[i - 1][j - 2] + vec[i - 2][j - 1] + vec[i - 2][j + 1];
            ++i;
            --j;
        }
    }

    std::cout << vec[n + 1][m + 1] << std::endl;

    return 0;
}
