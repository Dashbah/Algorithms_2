#include <iostream>

struct Node {
    int height = 0;
    Node *left_ = nullptr;
    Node *right_ = nullptr;
    int data_;
public:
    Node() = default;

    Node(int val) : data_(val) {}
};

class AVLTree {
public:
    AVLTree() {}

    int getHeight() {
        return size;
    }

    void insert(int value) {
        if (root_ == nullptr) {
            root_ = new Node(value);
            return;
        }
        insert(root_, value);
    }

    void erase(int value) {}

    int *find(int value) {}

    int *traversal() {}

    int *lowerBound(int value) {}

    bool empty() {}

    Node *getRoot() {}

    int getSize() {}

    ~AVLTree() {}

private:
    Node *root_ = nullptr;
    int size = 0;

    Node * insert(Node * curr, int value) {
        if (curr == nullptr) return new Node(value);
        if (value < curr->data_)
            curr->left_ = insert(curr->left_, value);
        else
            curr->right_ = insert(curr->right_, value);
        // return balance(curr);
    }

    Node * balance(Node *node) {
        std::cout << "balance baby" << node->data_ << std::endl;
    }
};