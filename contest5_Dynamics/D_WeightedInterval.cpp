//
// Created by Dashbah on 24.02.2023.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>

struct Interval {
    double left;
    double right;
    double weight;
    int p = -1;

    bool operator<=(const Interval &other) const {
        return std::tuple(right, left, weight) <= std::tuple(other.right, other.left, other.weight);
    }

    bool operator<(const Interval &other) const {
        return std::tuple(right, left, weight) < std::tuple(other.right, other.left, other.weight);
    }
};

double compute(std::vector<Interval> &intervals) {
    std::vector<double> dp(intervals.size());
    dp[0] = intervals[0].weight;
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].p != -1) {
            dp[i] = std::max(intervals[i].weight + dp[intervals[i].p], dp[i - 1]);
        } else {
            dp[i] = std::max(intervals[i].weight, dp[i - 1]);
        }
    }
    return dp.back();
}

int partition(std::vector<Interval> &vec, int start, int end) {
    Interval pivot = vec[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (vec[i] <= pivot) {
            count++;
        }
    }

    // Giving pivot element its correct position
    int pivot_index = start + count;
    std::swap(vec[pivot_index], vec[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivot_index && j > pivot_index) {
        while (vec[i] <= pivot) {
            i++;
        }
        while (pivot < vec[j]) {
            j--;
        }
        if (i < pivot_index && j > pivot_index) {
            std::swap(vec[i++], vec[j--]);
        }
    }

    return pivot_index;
}

void quickSort1(std::vector<Interval> &vector, int start, int end) {
    // base case
    if (start >= end) {
        return;
    }

    // partitioning the array
    int p = partition(vector, start, end);

    // Sorting the left part
    quickSort1(vector, start, p - 1);

    // Sorting the right part
    quickSort1(vector, p + 1, end);
}

void quickSort(std::vector<Interval> &vector) {
    quickSort1(vector, 0, vector.size() - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<Interval> vec(n);
    for (int i = 0; i < n; ++i) {
        Interval interval = Interval();
        std::cin >> interval.left >> interval.right >> interval.weight;
        vec[i] = interval;
    }

    quickSort(vec);

    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (vec[j].right <= vec[i].left) {
                vec[i].p = j;
                break;
            }
        }
    }

    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(4);
    std::cout << compute(vec);
    return 0;
}
