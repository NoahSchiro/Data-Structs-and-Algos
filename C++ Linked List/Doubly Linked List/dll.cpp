#ifndef DLL_H
#define DLL_H
#include <iostream>

/*
This entire structure is very similar to the Singly linked list, 
the only difference is in the doublyLinkedList.addToTail and 
doublyLinkedList.deleteFromTail, and I will only add comments there
*/

class DLLnode {
    public:
        int data;
        DLLnode* nextNode,* prevNode;

        DLLnode() {
            nextNode = prevNode = nullptr;
        }

        DLLnode(int inputData, DLLnode* inputNode = nullptr, DLLnode* inputPrev = nullptr) {
            data = inputData;
            nextNode = inputNode;
            prevNode = inputPrev;
        }
};

class doublyLinkedList {
    public:

        DLLnode* head,* tail;

        doublyLinkedList() {
            head = tail = nullptr;
        }

        ~doublyLinkedList() {

            for(DLLnode *p; !(head == nullptr); ) {
                p = head -> nextNode;
                delete head;
                head = p;
            }
        }

        void addToHead(int information) {

            head = new DLLnode(information, head);
            if (tail == nullptr) {
                tail = head;
            }
        }

        void addToTail(int information) {

            if(tail != nullptr) {
                
                tail = new DLLnode(information, nullptr, tail);
                tail -> prevNode -> nextNode = tail;

            } else {

                head = tail = new DLLnode(information);
            
            }
        }

        int deleteFromHead() {
            
            //Store the data so that we can return it
            int information = head -> data;

            DLLnode* temp = head;

            //If the list contains one element
            if (head == tail) {

                //Just reset the list back to 
                //it's base condition (everything is a nullptr)
                head = tail = nullptr;
            
            } else {

                //Otherwise, just make the new 
                //head the 2nd item in the list
                head = head -> nextNode;
            }

            //Delete the old info
            delete temp;

            //Return old info
            return information;
        }
        
        int deleteFromTail() {
            
            int information = tail -> data;

            if(head == tail) {
                
                delete head;
                head = tail = nullptr;
            
            } else {
                
                tail = tail -> prevNode;
                delete tail -> nextNode;
                tail -> nextNode = nullptr;
            
            }
            
            return information;
        }

        void deleteNode(int information) {

            //Executes if the list is not empty
            if (head != nullptr) {

                //Executes only when the list has one element and 
                //that element contains the information we want to delete
                if (head == tail && information == head -> data) {
                    
                    delete head;
                    
                    head = tail = nullptr;
                
                //Executes if the head contains the data we want to delete
                } else if (information == head -> data) {
                    
                    DLLnode* temp = head;
                    
                    head = head -> nextNode;

                    delete temp;
                
                } else {

                    //Dummy nodes
                    DLLnode* pred;
                    DLLnode* temp;

                    //Loops through the list in a convoluted way
                    for (pred = head, temp = head -> nextNode; 
                         temp != nullptr && !(temp -> data == information);
                         pred = pred -> nextNode, temp = temp -> nextNode);

                    //If this if statement fails, it means we have reached the end of the list and we can break out
                    if (temp != nullptr) {

                        pred -> nextNode = temp -> nextNode;

                        //If we are at the end, reset tail so that it equals pred
                        if (temp == tail) {

                            tail = pred;

                        }

                        //Delete the last temp
                        delete temp;
                    }
                }
            }
        }

        bool isInList(int information) {

            DLLnode* temp;

            //Loop through linked list while temp is not at the end of the list and while it is not equal to the value we are trying to find
            for(temp = head; temp != nullptr && !(temp -> data == information); temp = temp -> nextNode);

            //If this returns true then it means that we found the data
            return temp != nullptr;
        }
};

#endif