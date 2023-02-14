#include <iostream>
#include <vector>
#include <cmath>

// здесь корневая декомпозиция не совсем подходит(или вовсе), так как
// массив постоянно изменяется

enum operation { sum, xor_ };

class Structure {
private:
    std::vector<int> vector_;
    // size_t size;
    std::vector<int> sqrt_vec_;
    operation op_;
    int module_;

public:
    Structure(std::vector<int> vector, operation op, int module = 0)
            : vector_(std::move(vector)), op_(op), module_(module) {
        if (op_ == xor_) {
            sqrtDecompositionForXor();
        } else {
            sqrtDecompositionForSum();
        }
    }

    void sqrtDecompositionForSum() {
        int n = static_cast<int>(vector_.size());
        int size = ceil(sqrt(n));
        int length1 = ceil(n / (size * 1.0));
        sqrt_vec_.resize(size);
        for (auto i = 0; i < n; ++i) {
            sqrt_vec_[i / length1] += vector_[i];
            sqrt_vec_[i / length1] %= module_;
            if (sqrt_vec_[i / length1] < 0) {
                sqrt_vec_[i / length1] += module_;
            }
        }
    }

    void sqrtDecompositionForXor() {
        int n = static_cast<int>(vector_.size());
        int size = ceil(sqrt(n));
        int length1 = ceil(n / (size * 1.0));
        sqrt_vec_.resize(size);
        for (auto i = 0; i < n; ++i) {
            sqrt_vec_[i / length1] ^= vector_[i];
        }
    }

    void insert(int pos, int x) {
        // pos = static_cast<int>(pos);
        --pos;
        vector_.emplace_back(0);
        for (auto i = static_cast<int>(vector_.size()) - 2; i >= pos; --i) {
            vector_[i + 1] = vector_[i];
        }
        vector_[pos] = x;
    }

    void erase(int pos) {
        --pos;
        for (auto i = pos; i + 1 < static_cast<int>(vector_.size()); ++i) {
            vector_[i] = vector_[i + 1];
        }
        vector_.pop_back();
        // vector_.resize(vector_.size() - 1);
    }

    void change(int pos, int x) {
        --pos;
        vector_[pos] = x;
    }

    int at(int pos) const {
        --pos;
        return vector_[pos];
    }

    int64_t compute(size_t left, size_t right) const {
        --left;
        --right;
        int result = 0;
        int size = ceil(sqrt(vector_.size()));
        int length1 = ceil(vector_.size() / (size * 1.0));
        if (op_ == xor_) {
            while (left <= right) {
                if (left % length1 == 0 && left + length1 - 1 <= right) {
                    result ^= sqrt_vec_[left / length1];
                    left += length1;
                } else {
                    result ^= sqrt_vec_[left++];
                }
            }
        } else {
            while (left <= right) {
                if (left % length1 == 0 && left + length1 - 1 <= right) {
                    result += sqrt_vec_[left / length1];
                    left += length1;
                } else {
                    result ^= sqrt_vec_[left++];
                }
            }
        }

        return result;
    }

    size_t size() const {
        return vector_.size();
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    char sign;
    std::cin >> sign;
    operation op;
    int module = 0;
    if (sign == '^') {
        op = xor_;
    } else {
        std::cin >> module;
        op = sum;
    }
    int n;
    std::cin >> n;
    std::vector<int> vector(n);
    int num;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        vector[i] = num;
    }
    auto structure = Structure(vector, op, module);
    int q;
    std::cin >> q;
    std::string request;
    for (int i = 0; i < q; ++i) {
        std::cin >> request;
        if (request == "insert") {
            int pos;
            int x;
            std::cin >> pos >> x;
            structure.insert(pos, x);
            continue;
        }
        if (request == "erase") {
            int pos;
            std::cin >> pos;
            structure.erase(pos);
            continue;
        }
        if (request == "change") {
            int pos;
            int x;
            std::cin >> pos >> x;
            structure.change(pos, x);
            continue;
        }
        if (request == "at") {
            int pos;
            std::cin >> pos;
            std::cout << structure.at(pos) << std::endl;
            continue;
        }
        if (request == "compute") {
            int l, r;
            std::cin >> l >> r;
            std::cout << structure.compute(l, r) << std::endl;
            continue;
        }
        if (request == "size") {
            std::cout << structure.size() << std::endl;
            continue;
        }
    }
    return 0;
}
