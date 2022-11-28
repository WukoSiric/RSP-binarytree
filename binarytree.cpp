#include <iostream>

class BinaryTree {
    int item; 
    BinaryTree * parent = NULL;
    BinaryTree * left = NULL;
    BinaryTree * right = NULL;

    BinaryTree * find_min(BinaryTree * node) {
        if (node == NULL) return(NULL);

        if (node->left == NULL) {
            return node;
        }
        return find_min(node->left);
    }
public:
    BinaryTree(int item) {
        this->item = item;
    }

    void insert(BinaryTree ** node, int item, BinaryTree * parent) {
        BinaryTree * pointer; 

        if (*node == NULL) {
            pointer = new BinaryTree(item); 
            pointer->left = pointer->right = NULL;
            pointer->parent = parent; 
            *node = pointer; 
            return;
        }

        if (item < (*node)->item) {
            this->insert(&(*node)->left, item, *node);
        } else {
            this->insert(&(*node)->right, item, *node);
        }
    }

    void del(BinaryTree ** node, int item) {
        BinaryTree * pointer; 

        if (*node == NULL) {
            return;
        }

        if (item < (*node)->item) {
            this->del(&(*node)->left, item);
        } else if (item > (*node)->item) {
            this->del(&(*node)->right, item);
        } else {
            if ((*node)->right == NULL) {
                pointer = *node;
                *node = (*node)->left;
                delete pointer;
            } else if ((*node)->left == NULL) {
                pointer = *node;
                *node = (*node)->right;
                delete pointer;
            } else {
                pointer = this->find_min((*node)->right);
                (*node)->item = pointer->item;
                this->del(&(*node)->right, pointer->item);
            }
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

    void inorder(BinaryTree * node) {
        if (node == NULL) {
            return;
        }

        this->inorder(node->left);
        std::cout << node->item << " ";
        this->inorder(node->right);
    }
};

int main() {
    BinaryTree * tree = new BinaryTree(10);
    tree->insert(&tree, 9, NULL);
    tree->insert(&tree, 8, NULL);
    tree->insert(&tree, 7, NULL);
    tree->insert(&tree, 6, NULL);

    // Print tree
    tree->inorder(tree);

    // Delete node
    tree->del(&tree, 8);

    //Print tree
    std::cout << std::endl;
    tree->inorder(tree);
    return 0;
}