//
// Created by Dashbah on 07.02.2023.
//

#include <iostream>
#include <vector>

//
// Created by Dashbah on 04.02.2023.
//

struct Point {
    int id;
    int distance;
    unsigned char bytes[4];

    Point() = default;

    Point(int id, int distance) : id(id), distance(distance) {
        bytes[0] = (distance & 0x000000FF);
        bytes[1] = (distance & 0x0000FF00) >> 8;
        bytes[2] = (distance & 0x00FF0000) >> 16;
        bytes[3] = (distance & 0xFF000000) >> 24;
    }

public:
    static void sortByDistance(std::vector<Point> &vec) {
        for (size_t i = 1; i < vec.size(); ++i) {
            for (auto j = i; j > 0; --j) {
                while (vec[j].distance < vec[j - 1].distance) {
                    std::swap(vec[j], vec[j - 1]);
                }
            }
        }
    }

    //    bool operator<(Point other) const {
    //        return distance < other.distance;
    //    }
    //
    //    bool operator>(Point other) const {
    //        return distance > other.distance;
    //    }
};

std::vector<Point> countingSort(const std::vector<Point> &vec, int place, int min = 0,
                                int max = 255) {
    int k = max - min + 1;
    std::vector<int> b(k);
    for (auto &number : vec) {
        ++b[number.bytes[place]];
    }
    // array of partial sums
    for (int i = 1; i < k; ++i) {
        b[i] = b[i - 1] + b[i];
    }

    std::vector<Point> result(vec.size());
    for (int i = vec.size() - 1; i >= 0; --i) {
        result[--b[vec[i].bytes[place] - min]] = vec[i];
    }
    return result;
}

void digitalSorting(std::vector<Point> &vec) {
    for (int i = 0; i < 4; ++i) {
        vec = countingSort(vec, i);
    }
}

int distanceBetween(Point &village, Point &shelter) {
    return std::abs(village.distance - shelter.distance);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Point> villages(n);
    int distance;
    for (int i = 1; i <= n; ++i) {
        std::cin >> distance;
        villages[i - 1] = Point(i, distance);
    }
    int m;
    std::cin >> m;
    std::vector<Point> shelters(m);
    for (int i = 1; i <= m; ++i) {
        std::cin >> distance;
        shelters[i - 1] = Point(i, distance);
    }

    digitalSorting(villages);
    digitalSorting(shelters);

    // closer shelter for each village
    std::vector<int> result(n);
    int current_shelter_id = 0;
    for (auto &village : villages) {
        while (true) {
            auto current_distance = distanceBetween(village, shelters[current_shelter_id]);
            if (current_shelter_id == m - 1) {
                result[village.id - 1] = shelters[current_shelter_id].id;
                break;
            }
            auto next_distance = distanceBetween(village, shelters[current_shelter_id + 1]);
            if (current_distance <= next_distance) {
                result[village.id - 1] = shelters[current_shelter_id].id;
                break;
            }
            ++current_shelter_id;
        }
    }
    for (auto shelter : result) {
        std::cout << shelter << " ";
    }
    return 0;
}