#include <iostream>
#include <vector>
#include <algorithm>

struct Sculpture {
    int id;
    int value;
    int reqTime;

    bool operator<(const Sculpture other) const {
        return reqTime < other.reqTime;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, perfectSize;
    long long time;
    std::cin >> n >> perfectSize >> time;
    std::vector<Sculpture> sculptures(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sculptures[i].value;
        sculptures[i].id = i + 1;
        sculptures[i].reqTime = std::abs(sculptures[i].value - perfectSize);
    }

    std::sort(sculptures.begin(), sculptures.end());
    // std::qsort(sculptures.begin(), sculptures.end(), sizeof(int), comparator);
    // std::qsort(sculptures.begin(), sculptures.end());

    std::vector<int> res;
    int numOfGoodSculptures = 0;
    for (int i = 0; i < n; ++i) {
        int reqTime =  std::abs(sculptures[i].value - perfectSize);
        if (time < reqTime) {
            break;
        }
        ++numOfGoodSculptures;
        time -= reqTime;
        res.emplace_back(sculptures[i].id);
    }

    std::cout << numOfGoodSculptures << std::endl;
    for (auto elem : res) {
        // don't print " " at the end
        std::cout << elem << " ";
    }
    return 0;
}