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

    void insert(BinaryTree * node, int item, BinaryTree * parent) {
        BinaryTree * pointer; 

        if (node == NULL) {
            pointer = new BinaryTree(item); 
            pointer->left = pointer->right = NULL;
            pointer->parent = parent; 
            node = pointer; 
            return;
        }

        if (item < node->item) {
            this->insert(node->left, item, node);
        } else {
            this->insert(node->right, item, node);
        }
    }

    BinaryTree * search(BinaryTree * node, int item) {
        if (node == NULL) {
            return NULL;
        }

        if (node->item == item) {
            return node;
        }

        if (item < node->item) {
            return this->search(node->left, item); 
        } else {
            return this->search(node->right, item);
        }
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