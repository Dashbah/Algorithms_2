#include <stack>

class Queue {
public:
    void push(int value) {
        if (left_.empty()) {
            left_.push(std::pair<int, int>(value, value));
        } else {
            int min = (left_.top().second > value) ? value : left_.top().second;
            left_.push(std::pair<int, int>(value, min));
        }
    }

    int pop() {
        if (right_.empty()) {
            while (!left_.empty()) {
                right_.push(left_.top());
                left_.pop();
            }
        }
        int value = right_.top().first;
        right_.pop();
        return value;
    }

    int min() const {
        return std::min (left_.top().second, right_.top().second);
    }

private:
    std::stack<std::pair<int, int>> left_;
    std::stack<std::pair<int, int>> right_;
};