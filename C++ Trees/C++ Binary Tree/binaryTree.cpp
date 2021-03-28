#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
class BTnode {
    public:
        T data;
        BTnode* right;
        BTnode* left;

        BTnode() {
            right = left = nullptr;
        }

        BTnode(T inputData, BTnode* r = nullptr, BTnode* l = nullptr) {
            data = inputData;
            right = r;
            left = l;
        }
};

template<class T>
class binaryTree {

    BTnode<T>* root;

    public:

        binaryTree() {
            root = nullptr;
        }
};

#endif