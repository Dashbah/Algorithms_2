//
// Created by Dashbah on 22.12.2022.
//
// source: https://habr.com/ru/post/150732/
#include <iostream>
#include <vector>

struct Node {
    int height;
    Node *left = nullptr;
    Node *right = nullptr;
    int value = 0;

public:
    Node(int val) : value(val), height(1) {
    }

    ~Node() {
    }
};

class AVLTree {
public:
    AVLTree() {
    }

    int getHeight() {
        return root_->height;
    }

    void insert(int value) {
        if (root_ == nullptr) {
            root_ = new Node(value);
            ++size_;
            return;
        }
        ++size_;
        root_ = insert(root_, value);
    }

    void erase(int value) {
        root_ = remove(root_, value);
    }

    int *find(int value) {
        auto res = find(root_, value);
        if (res == nullptr) {
            return nullptr;
        }
        return &res->value;
    }


    int zapolnennost;
    std::vector<int> traversal() {
        zapolnennost = 0;
        std::vector<int> vec;
        // vec.resize(size_);
        inorderTraversal(root_, vec);
        return vec;
    }

    void inorderTraversal(Node *curr, std::vector<int>& vec) {
        if (curr) {
            inorderTraversal(curr->left, vec);
            vec.emplace_back(curr->value);
            inorderTraversal(curr->right, vec);
        }
    }

    int *lowerBound(int value) {
        auto res = lowerBound(root_, value);
        if (res == nullptr) {
            return nullptr;
        }
        return &res->value;
    }

    bool empty() {
        return size_ == 0;
    }

    Node *getRoot() {
        return root_;
    }

    int getSize() {
        return size_;
    }

    ~AVLTree() {
        destroy(root_);
    }

private:
    Node *root_ = nullptr;
    int size_ = 0;
    // int* numbers;
//    int numbers[10];
//    int zapolnennost = 0;

    Node *find(Node *node, int val) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->value == val) {
            return node;
        }
        if (val < node->value) {
            return find(node->left, val);
        } else {
            return find(node->right, val);
        }
    };

    Node *lowerBound(Node *node, int val, Node *curr_lb = nullptr) {
        curr_lb = nullptr;
        auto curr = node;
        while (curr != nullptr) {
            if (curr->value < val) {
                curr = curr->right;
            } else {
                curr_lb = curr;
                curr = curr->left;
            }
        }
        return curr_lb;
    };

    Node *insert(Node *curr, int value) {
        if (curr == nullptr) {
            return new Node(value);
        }
        if (value < curr->value) {
            curr->left = insert(curr->left, value);
        } else {
            if (curr->value == value) {
                --size_;
                return curr;
            }
            curr->right = insert(curr->right, value);
        }
        return balance(curr);
    }

    Node *balance(Node *node)  // балансировка узла p
    {
        fixHeight(node);
        if (balanceFactor(node) == 2) {
            if (balanceFactor(node->right) < 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        if (balanceFactor(node) == -2) {
            if (balanceFactor(node->left) > 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        return node;  // балансировка не нужна
    }

    int balanceFactor(Node *node) {
        return height(node->right) - height(node->left);
    }

    void fixHeight(Node *node) {
        auto hl = height(node->left);
        auto hr = height(node->right);
        node->height = (hl > hr ? hl : hr) + 1;
    }

    Node *rotateRight(Node *p)  // правый поворот вокруг p
    {
        Node *q = p->left;
        p->left = q->right;
        q->right = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    int height(Node *node) {
        return node ? node->height : 0;
    }

    Node *rotateLeft(Node *q)  // левый поворот вокруг q
    {
        Node *p = q->right;
        q->right = p->left;
        p->left = q;
        fixHeight(q);
        fixHeight(p);
        return p;
    }

    void destroy(Node *node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
            node = nullptr;
        }
    }

    Node *remove(Node *node, int val) {
        if (!node) {
            return nullptr;
        }
        if (val < node->value) {
            node->left = remove(node->left, val);
        } else {
            if (val > node->value) {
                node->right = remove(node->right, val);
            } else {
                --size_;
                Node *q = node->left;
                Node *r = node->right;
                delete node;
                if (!r) {
                    return q;
                }
                Node *min = findMin(r);
                min->right = removeMin(r);
                min->left = q;
                return balance(min);
            }
        }
        return balance(node);
    }

    Node *findMin(Node *p) {
        return p->left ? findMin(p->left) : p;
    }

    Node *removeMin(Node *p) {
        if (p->left == nullptr) {
            return p->right;
        }
        p->left = removeMin(p->left);
        return balance(p);
    }
};