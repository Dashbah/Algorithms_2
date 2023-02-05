//
// Created by Dashbah on 04.02.2023.
//

#include <iostream>
#include <vector>

class HeapSorted {
    std::vector<int> list_;
    int size_;

public:
    explicit HeapSorted(const std::vector<int> &vec) {
        size_ = static_cast<int>(vec.size());
        buildHeap(vec);
        for (int i = size_ - 1; i >= 0; --i) {
            list_[i] = getMax();
            heapify(0);
        }
    }

    std::vector<int> &getHeap() {
        return list_;
    }

private:
    int getMax() {
        int res = list_[0];
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

            int temp = list_[i];
            list_[i] = list_[largest_child];
            list_[largest_child] = temp;
            i = largest_child;
        }
    }

    void buildHeap(const std::vector<int> &vec) {
        list_ = vec;
        for (int i = size_ / 2; i >= 0; --i) {
            heapify(i);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    auto heap = new HeapSorted(vec);
    auto res = heap->getHeap();
    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << " ";
    }
}