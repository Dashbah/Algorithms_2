struct Node {
    int height;
    Node *left;
    Node *right;
    int value;
};

class AVLTree {
public:
    AVLTree();

    int getHeight();

    void insert(int value);

    void erase(int value);

    int *find(int value);

    int *traversal();

    int *lowerBound(int value);

    bool empty();

    Node *getRoot();

    int getSize();

    ~AVLTree();

private:
};