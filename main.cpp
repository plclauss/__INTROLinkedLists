#include <iostream>
#include "LinkedList.h"

int main() {
    Node head(1);
    Node nodeToAppend(2);
    head.appendToList(nodeToAppend);

    std::cout << "head points to: " << head.getAddressOfNext();
    std::cout << "address of nodetoappend: " << &nodeToAppend;
}
