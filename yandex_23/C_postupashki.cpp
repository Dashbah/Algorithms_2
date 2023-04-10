#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> input(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> input[i];
    }

    std::vector<std::pair<int, int>> suff(n + 1);
    for (int i = 1; i <= n; ++i) {
        suff[i] = {-1, -1};
    }

    int idMx = n;

    for (int i = n - 1; i >= 1; --i) {
        suff[i] = {idMx, i};
        if (suff[i + 1].first != -1 &&
            input[suff[i + 1].first] * input[suff[i].second] > input[suff[i].first] * input[suff[i + 1].second]) {
            suff[i] = suff[i + 1];
        }
        if (input[i] > input[idMx]) {
            idMx = i;
        }
    }

    int idMn = 1;
    std::pair<long long, long long> ans = {-1, -1};
    std::vector<int> idsAns;
    for (int i = 2; i <= n; ++i) {
        if (ans.first == -1 || ans.first * input[idMn] < ans.second * input[i]) {
            ans.first = input[i];
            ans.second = input[idMn];
            idsAns.clear();
            idsAns = {idMn, i};
        }
        if (suff[i + 1].first != -1) {
            std::pair<long long, long long> ch = {input[suff[i + 1].first], input[suff[i + 1].second]};
            if (ans.first == -1 || ans.first * ch.second * input[idMn] < ans.second * ch.first * input[i]) {
                ans.first = ch.first * input[i];
                ans.second = ch.second * input[idMn];
                idsAns.clear();
                idsAns = {idMn, i, suff[i + 1].second, suff[i + 1].first};
            }
        }
        if (input[idMn] > input[i]) idMn = i;
    }

    if (idsAns.empty() || ans.first <= ans.second) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << idsAns.size() / 2 << std::endl;
        for (int i = 0; i < idsAns.size(); i++) {
            if (i == 2) {
                std::cout << std::endl;
            }
            std::cout << idsAns[i] << " ";
        }
    }
}