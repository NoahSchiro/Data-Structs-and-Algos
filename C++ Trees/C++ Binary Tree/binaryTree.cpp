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

        //Inserts a new node into tree
        void insert(int information) {

            BTnode* temp = root, *previous = nullptr;

            //While our temp variable has not 
            //reached a leaf node, continue (skips this 
            //while loop if the tree is intially empty)
            while(temp != nullptr) {

                //Let the previous node equal
                //the node we are focusing on  
                previous = temp;
                
                //If our input variable is less then
                //the node we are focusing on, then
                //move down to the left side of the tree 
                if(information < temp -> data) {
                    
                    temp = temp -> left;
                
                //Same as above but greater then -> right
                } else {

                    temp = temp -> right;
                }
            }

            //Executes if tree is empty
            if(root == nullptr) {
            
                root = new BTnode(information);

            //Creates a new leaf
            } else if (information < previous -> data) {
                previous -> left = new BTnode(information);
            } else {
                previous -> right = new BTnode(information);
            }

        }
};

#endif