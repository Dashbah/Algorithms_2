#include <iostream>
#include <vector>

int heming(const std::vector<int> &a, size_t pos) {
    int answer = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (pos == a.size()) {
            pos = 0;
        }
        if (a[pos] != a[i]) {
            answer++;
        }
        pos++;
    }
    return answer;
}

void write(const std::vector<int> &a, size_t pos) {
    for (int i = 0; i < a.size() - 1; ++i) {
        if (pos == a.size()) {
            pos = 0;
        }
        std::cout << a[pos] << " ";
        pos++;
    }
    if (pos == a.size()) {
        pos = 0;
    }
    std::cout << a[pos];
}

bool same(const std::vector<int> &a, size_t pos1, size_t pos2) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[(i + pos1) % a.size()] != a[(i + pos2) % a.size()]) {
            return false;
        }
    }
    return true;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int maxx = -1;
    std::vector<size_t> answer;
    for (size_t pos = 0; pos < n; ++pos) {
        int cnt = heming(a, n - pos);
        if (cnt == maxx) {
            answer.push_back(pos);
        }
        if (cnt > maxx) {
            maxx = cnt;
            answer.clear();
            answer.push_back(pos);
        }
    }
    std::cout << maxx << std::endl;
    //    for (const auto &pos : answer) {
    //        write(a, n - pos);
    //        std::cout << "; " << pos << std::endl;
    //    }

    write(a, answer[0]);
    std::cout << "; " << answer[0] << std::endl;
    for (size_t i = 1; i < answer.size(); ++i) {
        bool already_exists = true;
        for (auto j = i - 1; j >= 0; --j) {
            if (!same(a, answer[i], answer[j])) {
                already_exists = false;
                break;
            }
        }
        if (!already_exists) {
            write(a, answer[i]);
            std::cout << "; " << answer[i] << std::endl;
        }
    }
}