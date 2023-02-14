// #include "Tree.h"
#include "AVL_tree.cpp"

int main() {
    auto avl_tree = AVLTree();
    int elem;
    do {
        std::cin >> elem;
        if (elem == 0) {
            break;
        }
        avl_tree.insert(elem);
    } while (elem != 0);
    std::cout << "finish";
    return 0;
}