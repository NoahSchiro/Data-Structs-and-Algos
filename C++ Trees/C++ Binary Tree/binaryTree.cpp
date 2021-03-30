#ifndef BINARYTREE_H
#define BINARYTREE_H


class BTnode {
    public:
        int data;
        BTnode* right;
        BTnode* left;

        BTnode() {
            right = left = nullptr;
        }

        BTnode(int inputData, BTnode* r = nullptr, BTnode* l = nullptr) {
            data = inputData;
            right = r;
            left = l;
        }
};


class binaryTree {

    BTnode* root;

    public:

        binaryTree() {
            root = nullptr;
        }
};

#endif