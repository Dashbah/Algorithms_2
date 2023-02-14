#include <iostream>
#include <vector>

// all got OK

class Tree {
private:
    struct Node {
        Node() {
        }

        ~Node() {
        }

        Node *left_ = nullptr;
        Node *right_ = nullptr;
        int data_ = 0;
    };

    Node *root_ = nullptr;

    void destroy(Node *node) {
        if (node) {
            destroy(node->left_);
            destroy(node->right_);
            delete node;
            node = nullptr;
        }
    }

    void ins(Node *curr, int value) {
        if (value < (curr)->data_) {
            if (!curr->left_) {
                curr->left_ = new Node();
                curr->left_->data_ = value;
                return;
            }
            ins(curr->left_, value);
        } else if (value != (curr)->data_) {
            if (!curr->right_) {
                curr->right_ = new Node();
                curr->right_->data_ = value;
                return;
            }
            ins(curr->right_, value);
        }
    }

    size_t height(Tree::Node *node) {
        if (node == nullptr) {
            return 0;
        } else if (node->left_ == nullptr && node->right_ == nullptr) {
            return 0;
        } else {
            auto hl = height(node->left_);
            auto hr = height(node->right_);
            auto h = hl > hr ? hl + 1 : hr + 1;
            return h;
        }
    }

    int max21(Node *curr) {
        int m = 0;
        if (curr->right_) {
            while (curr->right_->right_) {
                curr = curr->right_;
            }
            if (!curr->right_) {
                return curr->left_->data_;
            }
            if (!curr->right_->left_) {
                return curr->data_;
            } else {
                curr = curr->right_->left_;
                while (curr->right_) {
                    curr = curr->right_;
                }
                m = curr->data_;
            }
            return m;
        } else {
            curr = curr->left_;
            while (curr->right_) {
                curr = curr->right_;
            }
            return curr->data_;
        }
    }

    void inorderTraversal(Node *curr) {
        if (curr) {
            inorderTraversal(curr->left_);
            std::cout << curr->data_ << std::endl;
            inorderTraversal(curr->right_);
        }
    }

    void printLeaves1(Node *curr) {
        if (curr) {
            printLeaves1(curr->left_);
            if (!curr->left_ && !curr->right_) {
                std::cout << curr->data_ << std::endl;
            }
            printLeaves1(curr->right_);
        }
    }

public:
    Tree() {
    }

    ~Tree() {
        destroy(root_);
    }

    void insert(int value) {
        if (!root_) {
            root_ = new Node();
            root_->data_ = value;
        } else {
            ins(root_, value);
        }
    }

    size_t getHeight() {
        return height(root_) + 1;
    }

    int max2() {
        return max21(root_);
    }

    void printOrdered() {
        inorderTraversal(root_);
    }

    void printLeaves() {
        printLeaves1(root_);
    }
};

int main() {
    auto tree = Tree();
    std::vector<int> nums;
    int elem;
    while (true) {
        std::cin >> elem;
        if (elem == 0) {
            break;
        }
        nums.emplace_back(elem);
    }
    for (auto num : nums) {
        tree.insert(num);
    }
    tree.printLeaves();
    return 0;
}