#include <cstdlib>
#include <stdexcept>
#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node *previous;

    explicit Node(int value) : data(value), next(nullptr), previous(nullptr) {
    }

    ~Node() {
    }
};

class List {
public:
    List() : head(nullptr), tail(nullptr), size_(0) {
    }

    List(int const *values, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            if (!correctValue(values[i])) {
                throw std::runtime_error("Wrong Value!");
            }
        }
        for (size_t i = 0; i < size; ++i) {
            pushBack(values[i]);
        }
        size_ = size;
    }

    ~List() {
        while (size_ != 0) {
            auto tmp = head->next;
            delete head;
            head = tmp;
            --size_;
        }
    }

    void pushBack(int value) {
        if (!correctValue(value)) {
            this->~List();
            throw std::runtime_error("Wrong Value!");
        } else {
            if (head == nullptr) {
                head = new Node(value);
                tail = head;
            } else {
                auto tmp = new Node(value);
                tail->next = tmp;
                tmp->previous = tail;
                tail = tmp;
            }
            head->previous = tail;
            tail->next = head;
            ++size_;
        }
    }

    void pushFront(int value) {
        if (!correctValue(value)) {
            this->~List();
            throw std::runtime_error("Wrong Value!");
        }
        if (head == nullptr) {
            head = new Node(value);
            tail = head;
        } else {
            auto tmp = new Node(value);
            head->previous = tmp;
            tmp->next = head;
            head = tmp;
        }
        head->previous = tail;
        tail->next = head;
        ++size_;
    }

    int pop() {
        if (size_ == 0) {
            this->~List();
            throw std::runtime_error("Can not pop such element!");
        }
        int value = head->data;
        if (size_ == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            --size_;
        } else {
            if (size_ == 2) {
                delete head;
                head = nullptr;
                head = tail;
                --size_;
            } else {
                auto tmp = head->next;
                delete head;
                // head = nullptr;
                head = tmp;
                --size_;
            }
            head->previous = tail;
            tail->next = head;
        }
        return value;
    }

    int pop(size_t position) {
        if (position + 1 >= size_) {
            this->~List();
            throw std::runtime_error("Wrong Position!");
        }
        int value = 0;
        if (size_ == 1) {
            value = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            if (size_ == 2) {
                value = tail->data;
                delete tail;
                tail = nullptr;
                tail = head;
                --size_;
            } else {
                if (position + 2 == size_) {
                    value = tail->data;
                    auto tmp = tail->previous;
                    delete tail;
                    tail = nullptr;
                    tail = tmp;
                    --size_;
                } else {
                    size_t flag = 0;
                    --size_;
                    for (auto i = head; i != tail;) {
                        if (flag++ == position) {
                            value = i->next->data;
                            auto tmp = i->next->next;
                            delete i->next;
                            i->next = nullptr;
                            tmp->previous = i;
                            i->next = tmp;
                            break;
                        }
                        i = i->next;
                    }
                }
            }
            head->previous = tail;
            tail->next = head;
        }
        return value;
    }

    void push(int value, size_t position) {
        if (!correctValue(value)) {
            this->~List();
            throw std::runtime_error("Wrong Value!");
        }
        if (position + 1 > size_) {
            this->~List();
            throw std::runtime_error("Wrong Position!");
        }
        auto new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = head;
        } else {
            if (position + 1 == size_) {
                tail->next = new_node;
                new_node->previous = tail;
                tail = new_node;
                tail->next = head;
                head->previous = tail;
            } else {
                size_t flag = 0;
                for (auto i = head; i != tail;) {
                    if (flag++ == position) {
                        new_node->next = i->next;
                        new_node->previous = i;
                        i->next->previous = new_node;
                        i->next = new_node;
                        break;
                    }
                    i = i->next;
                }
            }
        }
        ++size_;
    }

    void printList() const {
        if (size_ == 0) {
            return;
        }
        Node *cur = head;
        while (cur != tail) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << tail->data << std::endl;
    }

    static bool correctValue(int value) {
        return abs(value) <= 2'000'000'000;
    }

    Node *head{};
    Node *tail{};
    size_t size_;
};

int main() {
    int *arr = new int[]{1, 2, 3, 4, 5, 6};
    auto list = List(arr, 6);
    list.printList();
    list.pushBack(7);
    list.push(8, 3);
    list.pushFront(0);
    list.pop();
    list.pop(5);
    list.printList();
    auto list1 = List();
    list1.pushBack(1);
    list1.printList();
    list1.pushBack(2);
    list1.printList();
    list1.pop(0);
    list1.pop();
    list1.printList();
    // list1.pop();
    list1.printList();
    list1.pushFront(3);
    list1.printList();
    list1.pushFront(4);
    list1.printList();
    list1.push(5, 1);
    list1.printList();
    try {
        list1.pushBack(2'000'000'001);
    } catch (std::runtime_error e) {
    }
    // list1.pushBack(2'000'000'001);
    list1.printList();
}