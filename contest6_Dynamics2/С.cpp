//
// Created by Dashbah on 15.03.2023.
//
#include <iostream>
#include <vector>
#include <utility>

struct Rock{
    int weight;
    int price;
    double q;

    bool operator<=(const Rock &other) const {
        return std::tuple(other.q, other.price) <= std::tuple(q, price);
    }

    bool operator<(const Rock &other) const {
        return std::tuple(other.q, other.price) <  std::tuple(q, price);
    }
};

int partition(std::vector<Rock> *vec, int start, int end) {
    Rock pivot = vec->at(start);

    int count = 0;
    for (int i = start + 1; i <= end; ++i) {
        if (vec->at(i) <= pivot) {
            count++;
        }
    }

    // Giving pivot element its correct position
    int pivot_index = start + count;
    std::swap(vec[pivot_index], vec[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivot_index && j > pivot_index) {
        while (vec->at(i) <= pivot) {
            i++;
        }
        while (pivot < vec->at(i)) {
            j--;
        }
        if (i < pivot_index && j > pivot_index) {
            std::swap(vec[i++], vec[j--]);
        }
    }

    return pivot_index;
}

void quickSort1(std::vector<Rock> *vector, int start, int end) {
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

void quickSort(std::vector<Rock> *vector) {
    quickSort1(vector, 0, vector->size() - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t n, w;
    std::cin >> n >> w;
    std::vector<Rock> rocks(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> rocks[i].weight;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> rocks[i].price;
        rocks[i].q = rocks[i].price * 1.0 / rocks[i].weight;
    }

    quickSort(&rocks);

    int64_t sum = 0;
    int64_t weight = 0;
    int64_t num = 0;

    std::vector<Rock> taken;
    for (int i = 0; i < n; ++i) {
        if (weight + rocks[i].weight <= w) {
            weight += rocks[i].weight;
            sum += rocks[i].price;
            ++num;
            taken.emplace_back(rocks[i]);
            if (weight == w) {
                break;
            }
        }
    }

    std::cout << sum << std::endl;
    std::cout << weight << std::endl;
    std::cout << num << std::endl;

    for (auto &rock : taken) {
        std::cout << rock.weight << " ";
    }
    std::cout << std::endl;
    for (auto &rock : taken) {
        std::cout << rock.price << " ";
    }
    return 0;
}
