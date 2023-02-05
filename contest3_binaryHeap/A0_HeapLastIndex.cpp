//
// Created by Dashbah on 04.02.2023.
//

#include <iostream>
#include <vector>

class buildHeap {
    std::vector<int> list;

public:
    void add(int value) {
        list.push_back(value);
        if (heapSize() == 1) {
            return;
        }
        int i = heapSize() - 1;
        int parent = (i - 1) / 2;

        while (i > 0 && list[parent] < list[i]) {
            int temp = list[i];
            list[i] = list[parent];
            list[parent] = temp;

            i = parent;
            parent = (i - 1) / 2;
        }
    }

    size_t heapSize() {
        return list.size();
    }

    int lastElement() {
        return list.back();
    }
};

int main() {
    int n;
    std::cin >> n;

    auto heap = new buildHeap();
    int value;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        heap->add(value);
    }
    std::cout << heap->lastElement() << std::endl;
    return 0;
}