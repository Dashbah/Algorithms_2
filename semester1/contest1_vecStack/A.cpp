#include <iostream>
#include <vector>
#include <exception>

class Stack {
public:
    void push(int value) {
        vec_.emplace_back(value);
    }

    int pop() {
        if (!vec_.empty()) {
            int el = vec_.back();
            vec_.pop_back();
            return el;
        } else {
            throw std::invalid_argument("error");
        }
    }

    int back() const {
        if (!vec_.empty()) {
            return vec_.back();
        } else {
            throw std::invalid_argument("error");
        }
    }

    size_t size() const {
        return vec_.size();
    }

    void clear() {
        vec_ = std::vector<int>();
    }

private:
    std::vector<int> vec_;
};

int main() {
    Stack stack = Stack();
    stack.back();
    stack.size();
    stack.push(1);
    int a = stack.back();
    stack.pop();
    stack.clear();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
