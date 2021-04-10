#include "dll.cpp"

int main() {

    doublyLinkedList list;

    for(int i = 1; i < 100; i *= 2) {
        list.addToHead(i);
    }

    std::cout << list.isInList(32) << "\n";

    DLLnode* temp = nullptr;
    for(temp = list.head; temp != nullptr; temp = temp -> nextNode) {
        std::cout << temp -> data << "\n";
    }

    DLLnode* te = nullptr;
    for(te = list.tail; te != nullptr; te = te -> prevNode) {
        std::cout << temp -> data << "\n";
    }
}