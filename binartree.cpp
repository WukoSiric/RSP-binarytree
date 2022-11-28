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
};

int main() {

    return 0;
}