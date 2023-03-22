#include <iostream>
#include <vector>

bool ok(const std::vector<int> &ql, const std::vector<long long> &qr, int n, int s, int c) {
    int countMaxRight = 0;
    int countMaxLeft = 0;
    for (int i = 1; i <= n; i++) {
        if (qr[i] >= c) {
            ++countMaxRight;
        }
        if (ql[i] > c) {
            ++countMaxLeft;
        }
    }
    if (countMaxRight < (n + 1) / 2) {
        return false;
    }
    long long sum = 0;
    for (int i = n; i >= (n + 1) / 2; i--) {
        if (ql[i] <= c) {
            sum += (c - ql[i]);
        }
    }
    return sum <= s;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, s;
    std::cin >> n >> s;
    std::vector<int> mins(n + 1);
    std::vector<long long> maxes(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> mins[i] >> maxes[i];
    }

    for (int i = 1; i <= n; i++) {
        s -= mins[i];
    }

    std::sort(mins.begin(), mins.end());
    std::sort(maxes.begin(), maxes.end());

    int l = mins[(n + 1) / 2];
    int r = 1e9 + 10;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mins, maxes, n, s, mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
