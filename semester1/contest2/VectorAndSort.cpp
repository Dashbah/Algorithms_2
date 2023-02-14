#include <iterator>
#include <initializer_list>
#include <stdexcept>
#include <array>

class Vector {
public:
    struct Iterator {
        using IteratorCategory = std::random_access_iterator_tag;
        using DifferenceType = std::ptrdiff_t;

        explicit Iterator(int *ptr) : m_ptr_(ptr){};

        int &operator*() const {
            return *m_ptr_;
        }

        int *operator->() {
            return m_ptr_;
        }

        int *getIterator() {
            return m_ptr_;
        }

        Iterator &operator++() {
            ++m_ptr_;
            return *this;
        }

        Iterator operator++(int) {
            int *tmpr = m_ptr_;
            ++m_ptr_;
            return Iterator(tmpr);
        }

        Iterator &operator--() {
            --m_ptr_;
            return *this;
        }

        Iterator operator--(int) {
            int *tmpr = m_ptr_;
            --m_ptr_;
            return Iterator(tmpr);
        }

        Iterator operator+(const DifferenceType &movement) {
            return Iterator(movement + m_ptr_);
        }

        Iterator operator-(const DifferenceType &movement) {
            return Iterator(m_ptr_ - movement);
        }

        Iterator &operator+=(const DifferenceType &movement) {
            m_ptr_ += movement;
            return *this;
        }

        Iterator &operator-=(const DifferenceType &movement) {
            m_ptr_ -= movement;
            return *this;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) {
            return a.m_ptr_ == b.m_ptr_;
        }

        friend bool operator!=(const Iterator &a, const Iterator &b) {
            return !(a == b);
        }

    private:
        int *m_ptr_;
    };

    Vector() : size_(0), capacity_(10), vec_(new int[10]) {
    }

    explicit Vector(size_t n_size)
            : size_(n_size), capacity_(2 * size_), vec_(new int[2 * n_size]) {
        for (size_t i = 0; i < n_size; ++i) {
            vec_[i] = 0;
        }
    }

    Vector(const int *vals, size_t size)
            : size_(size), capacity_(2 * size), vec_(new int[2 * size]) {
        for (size_t i = 0; i < size; ++i) {
            vec_[i] = vals[i];
        }
    }

    Vector(const Vector &vec)
            : size_(vec.getSize()), capacity_(2 * vec.getSize()), vec_(new int[2 * vec.getSize()]) {
        for (size_t i = 0; i < vec.getSize(); ++i) {
            vec_[i] = vec[i];
        }
    }

    Vector(std::initializer_list<int> vals)
            : size_(vals.size()), capacity_(2 * vals.size()), vec_(new int[2 * vals.size()]) {
        size_t i = 0;
        for (int val : vals) {
            vec_[i++] = val;
        }
    }

    ~Vector() {
        delete[] vec_;
    }

    size_t getSize() const {
        return size_;
    }

    size_t getCapacity() const {
        return capacity_;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    void reserve(size_t n_capacity) {
        if (n_capacity > capacity_) {
            int *tmp = new int[n_capacity];
            for (size_t i = 0; i < size_; ++i) {
                tmp[i] = vec_[i];
            }
            delete[] vec_;
            vec_ = tmp;
            capacity_ = n_capacity;
        }
    }

    void resize(size_t n_size) {
        if (n_size > size_) {
            if (n_size >= capacity_) {
                reserve(n_size * 2);
            }
            for (size_t i = size_; i < n_size; ++i) {
                vec_[i] = 0;
            }
        }
        size_ = n_size;
    }

    void pushBack(int value) {
        if (size_ == capacity_) {
            reserve(2 * capacity_);
        }
        vec_[size_] = value;
        ++size_;
    }

    void popBack() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        } else {
            --size_;
        }
    }

    void clear() {
        size_ = 0;
    }

    void insert(size_t pos, int value) {
        if (pos > size_) {
            throw std::runtime_error("Wrong Position!");
        } else {
            if (size_ == capacity_) {
                reserve(capacity_ * 2);
            }
            for (size_t i = size_; i > pos; --i) {
                vec_[i] = vec_[i - 1];
            }
            vec_[pos] = value;
            ++size_;
        }
    }

    void erase(size_t pos) {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        if (pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }
        for (size_t i = pos; i < size_ - 1; ++i) {
            vec_[i] = vec_[i + 1];
        }
        --size_;
    }

    int at(size_t pos) {
        if (pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }
        return vec_[pos];
    }

    int front() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        return vec_[0];
    }

    int back() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        return vec_[size_ - 1];
    }

    Iterator begin() {
        return Iterator(vec_);
    }

    Iterator end() {
        return Iterator(vec_ + size_);
    }

    int &operator[](size_t pos) const {
        if (pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }
        return vec_[pos];
    }

    Vector &operator=(const Vector &other) {
        if (this != &other) {
            int *tmp = new int[other.capacity_];
            for (size_t i = 0; i < other.size_; ++i) {
                tmp[i] = other[i];
            }
            delete[] vec_;
            vec_ = tmp;
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }

private:
    size_t size_;
    size_t capacity_;
    int *vec_;
};

void merge(Vector::Iterator begin, const Vector::Iterator mid, const Vector::Iterator end) {
    Vector v;
    auto it_l{begin}, it_r{mid};
    auto it_mid{mid}, it_end{end};

    while (it_l != it_mid && it_r != it_end) {
        v.pushBack((*it_l <= *it_r) ? *it_l++ : *it_r++);
    }
    for (auto i = it_l; i != it_mid; ++i) {
        v.pushBack(*i);
    }
    for (auto i = it_r; i != it_end; ++i) {
        v.pushBack(*i);
    }
    for (auto num : v) {
        *begin = num;
        ++begin;
    }
}

void mergeSort(Vector::Iterator begin, Vector::Iterator end) {
    auto size = std::distance(begin.getIterator(), end.getIterator());
    if (size < 2) {
        return;
    }

    auto mid = begin + size / 2;
    mergeSort(begin, mid);
    mergeSort(mid, end);
    merge(begin, mid, end);
}

void insertionSort(Vector::Iterator begin, Vector::Iterator end) {
    for (auto current = begin; current != end; ++current) {
        for (auto j = current; j != begin && *(j - 1) > *j; --j) {
            int val = *(j - 1);
            *(j - 1) = *j;
            *j = val;
        }
    }
}