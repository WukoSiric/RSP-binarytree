#include <iostream>

class BinaryTree {
    int item; 
    BinaryTree * parent = NULL;
    BinaryTree * left = NULL;
    BinaryTree * right = NULL;
public:
    BinaryTree(int item) {
        this->item = item;
    }

    void in_order(BinaryTree * node) {
        if (node != NULL) {
            in_order(node->left);
            std::cout << node->item << std::endl;
            in_order(node->right);
        }
    }

    void pre_order(BinaryTree * node) {
        if (node != NULL) {
            std::cout << node->item << std::endl;
            in_order(node->left);
            in_order(node->right);
        }
    }
};

int main() {

    return 0;
}