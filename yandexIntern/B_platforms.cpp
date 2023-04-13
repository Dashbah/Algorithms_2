#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> platforms(n);
    std::vector<long long> people(m);

    for (int i = 0; i < n; ++i) {
        std::cin >> platforms[i];
    }
    long long maxTop = platforms[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        platforms[i] -= maxTop;
        if (platforms[i] + maxTop > maxTop) {
            maxTop = platforms[i] + maxTop;
        }
    }
    for (int i = 0; i < m; i++) {
        std::cin >> people[i];
    }

    std::sort(platforms.begin(), platforms.end());
    std::sort(people.begin(), people.end());

    int ans = 0, j = 0;
    for (long long i : people) {
        for (; j < platforms.size(); ++j) {
            if (i <= platforms[j]) {
                ++ans;
                ++j;
                break;
            }
        }
     }

    std::cout << ans << std::endl;
    return 0;
}