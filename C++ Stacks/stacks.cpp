#ifndef STACKS_H
#define STACKS_H

#include <list>

class stack {
    
    std::list<int> lst;

    public:

        void clear() {
            lst.clear();
        }

        bool isEmpty() {
            return lst.empty();
        }

        int topElement() {
            return lst.back();
        }

        int pop() {

            int temp = lst.back();
            lst.pop_back();
            return temp;
        
        }

        void push(int information) {
            lst.push_back(information);
        }
};

#endif