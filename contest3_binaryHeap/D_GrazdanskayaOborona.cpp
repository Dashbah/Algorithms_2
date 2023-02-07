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

    Point() = default;

    Point(int id, int distance) : id(id), distance(distance) {
    }

    static void sortByDistance(std::vector<Point> &vec) {
        for (size_t i = 1; i < vec.size(); ++i) {
            for (auto j = i; j > 0; --j) {
                while (vec[j].distance < vec[j - 1].distance) {
                    std::swap(vec[j], vec[j - 1]);
                }
            }
        }
    }

    bool operator<(Point other) const {
        return distance < other.distance;
    }

    bool operator>(Point other) const {
        return distance > other.distance;
    }
};

template <class ValueType>
class HeapSorted {
    std::vector<ValueType> list_;
    int size_;

public:
    explicit HeapSorted(const std::vector<ValueType> &vec) {
        size_ = static_cast<int>(vec.size());
        buildHeap(vec);
        for (int i = size_ - 1; i >= 0; --i) {
            list_[i] = getMax();
            heapify(0);
        }
    }

    std::vector<ValueType> &getHeap() {
        return list_;
    }

private:
    ValueType getMax() {
        ValueType res = list_[0];
        list_[0] = list_[size_ - 1];
        --size_;
        return res;
    }

    void heapify(int i = 0) {
        int left_child;
        int right_child;
        int largest_child;

        for (;;) {
            left_child = 2 * i + 1;
            right_child = 2 * i + 2;
            largest_child = i;

            if (left_child < size_ && list_[left_child] > list_[largest_child]) {
                largest_child = left_child;
            }
            if (right_child < size_ && list_[right_child] > list_[largest_child]) {
                largest_child = right_child;
            }
            if (largest_child == i) {
                break;
            }

            ValueType temp = list_[i];
            list_[i] = list_[largest_child];
            list_[largest_child] = temp;
            i = largest_child;
        }
    }

    void buildHeap(const std::vector<ValueType> &vec) {
        list_ = vec;
        for (int i = size_ / 2; i >= 0; --i) {
            heapify(i);
        }
    }
};

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

    HeapSorted<Point> heap_villages = HeapSorted<Point>(villages);
    HeapSorted<Point> heap_shelters = HeapSorted<Point>(shelters);

    villages = heap_villages.getHeap();
    shelters = heap_shelters.getHeap();

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