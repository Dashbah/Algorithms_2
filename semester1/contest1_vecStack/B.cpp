//
// Created by Dashbah on 15.09.2022.
//
#include <iostream>
#include <deque>

class Deque {
public:
    void pushBack(int value) {
        left_.emplace_front(value);
        if (left_.size() > right_.size()) {
            right_.emplace_front(left_.back());
            left_.pop_back();
        }
    }

    void pushMiddle(int value) {
        if (left_.size() == right_.size()) {
            right_.emplace_front(value);
        } else {
            left_.emplace_back(value);
        }
    }

    int popFront() {
        int first_element = right_.back();
        right_.pop_back();
        if (left_.size() > right_.size()) {
            right_.emplace_front(left_.back());
            left_.pop_back();
        }
        return first_element;
    }

    int front() const {
        return right_.back();
    }

    int back() const {
        if (left_.empty()) {
            return right_.front();
        }
        return left_.front();
    }

    size_t size() const {
        return left_.size() + right_.size();
    }

private:
    std::deque<int> left_;
    std::deque<int> right_;
};

int main() {
    Deque deque = Deque();
    deque.size();
    deque.back();
    deque.front();
    deque.popFront();
    deque.pushBack(5);
    deque.pushMiddle(3);
}