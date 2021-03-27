#ifndef SLL_H
#define SLL_H

//Stores the data in the list and directs to the next node
class SLLnode {
    public:

        int data;
        SLLnode* nextNode;

        //Can be created without another node
        //or data
        SLLnode() {
            nextNode = nullptr;
        }

        //Can be created with another node
        //and data
        SLLnode(int i, SLLnode* next = 0) {
            data = i;
            nextNode = next;
        }
};

class singlyLinkedList {

    //First item in list
    SLLnode* head;
    //Last item in list
    SLLnode* tail;

    public:

        //Constructor
        singlyLinkedList() {
            head = tail = nullptr;
        }

        //Returns whether the list is empty 
        bool isEmpty() {
            return head == 0;
        }

        //Decontructor
        ~singlyLinkedList() {

            //Loop through all nodes as long as 
            //the list is not empty, delete each 
            //node and move to the next node
            for(SLLnode *p; !isEmpty; ) {
                p = head -> nextNode;
                delete head;
                head = p;
            }
        }

        //Adds information to the front of the list
        void addToHead(int information) {

            head = new SLLnode(information, head);
            if (tail == nullptr) {
                tail = head;
            }
        }

        //Adds information to the end of the list
        void addToTail(int information) {

            //If the list is not empty
            if (tail != nullptr) {

                //Adds via the next node
                tail -> nextNode = new SLLnode(information);
                
                //Set the new tail to the node that was just created
                tail = tail -> nextNode;

            } else {
                //If the list IS empty, both the head and 
                //tail must be equal to this new node
                head = tail = new SLLnode(information);
            }
        }

        //Deletes information from the 
        //first item in the list
        int deleteFromHead() {
            
            //Store the data so that we can return it
            int information = head -> data;

            SLLnode* temp = head;

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

        //Deletes information from the last item in the list
        int deleteFromTail() {

            //Lines 119 - 124 are consistent with lines 90 - 100
            int information = tail -> data;

            if (head == tail) {
                
                head = tail = nullptr;

            } else {

                //Create a temp node
                SLLnode* temp;

                //Increment to the second to last node
                for(temp = head; temp != tail; temp = temp -> nextNode);

                //Get rid of the tail
                delete tail;
                //Assign the second to last node to be the new tail
                tail = temp;
                //Make sure that it points to something (nothing lol)
                tail -> nextNode = nullptr;
            }
        }
};

#endif