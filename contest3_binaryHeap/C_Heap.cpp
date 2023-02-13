#include <initializer_list>
#include <vector>

//
// Created by Dashbah on 06.02.2023.
//
template <class ValueType>
class Heap {
public:
    Heap() {
    }

    template <class Iterator>
    Heap(Iterator begin, Iterator end) {
        std::vector<ValueType> vec;
        vec.insert(vec.begin(), begin, end);
        buildHeap(vec);
    }

    Heap(std::initializer_list<ValueType> initializer_list) {
        std::vector<ValueType> vec;
        vec.insert(vec.begin(), initializer_list.begin(), initializer_list.end());
        buildHeap(vec);
    }

    Heap(const Heap &other) : list_(other.list_) {
    }

    Heap &operator=(const Heap &heap) {
        list_ = heap.list_;
        return *this;
    }

    Heap(Heap &&other_heap) : list_(std::move(other_heap.list_)) {
    }

    Heap &operator=(Heap &&other) {
        list_ = std::move(other.list_);
        size_ = list_.size();
        return *this;
    }

    ~Heap() = default;

    size_t size() const {
        return list_.size();
    }

    bool empty() const {
        return list_.size() == 0;
    }

    void insert(const ValueType &value) {
        list_.push_back(value);
        ++size_;
        if (list_.size() == 1) {
            return;
        }
        auto i = list_.size() - 1;
        auto parent = (i - 1) / 2;

        while (i > 0 && list_[parent] < list_[i]) {
            ValueType temp = list_[i];
            list_[i] = list_[parent];
            list_[parent] = temp;

            i = parent;
            parent = (i - 1) / 2;
        }
    }

    ValueType extract() {
        ValueType res = list_[0];
        list_[0] = list_[list_.size() - 1];
        list_.pop_back();
        --size_;
        heapify(0);
        return res;
    }

    void sortHeap() {
        size_ = static_cast<int>(list_.size());
        buildHeap(list_);
        for (auto i = size_ - 1; i >= 0; --i) {
            list_[i] = getMax();
            heapify(0);
        }
    }

private:
    void buildHeap(const std::vector<ValueType> &vec) {
        size_ = static_cast<int>(list_.size());
        list_ = vec;
        for (int i = static_cast<int>(list_.size()) / 2; i >= 0; --i) {
            heapify(i);
        }
    }

    int getMax() {
        int res = list_[0];
        list_[0] = list_[size_ - 1];
        --size_;
        return res;
    }

    void heapify(int i) {
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

    std::vector<ValueType> list_;
    int size_ = 0;
};

int main() {
    std::initializer_list<int> list = {3, 4, 5, 2, 1};
    Heap<int> heap = Heap<int>(list);
    //  auto heap = Heap<int>();
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Heap<int> heap_vec = Heap<int>(vec.begin(), vec.end());


    heap.size();
    heap.empty();
    heap.insert(4);
    heap.extract();

    heap = heap_vec;
    auto heap2 = Heap<int>(heap);

    Heap<int> heap_to_sort = Heap<int>({5, 7, 2, 2, 1, 3, 4});
    heap_to_sort.sortHeap();

    return 0;
}