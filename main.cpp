#include <iostream>
#include "LinkedList.h"

int main() {;
    LinkedList pointerToHead;
    Node* head = new Node;

    head->setVal(1);
    pointerToHead.insertNode(*head, 0);
    pointerToHead.printList();
    std::cout << "1" << std::endl << std::endl;

    Node* node1 = new Node;
    node1->setVal(2);
    pointerToHead.insertNode(*node1, 1);
    pointerToHead.printList();
    std::cout << "2" << std::endl << std::endl;

    Node* node2 = new Node;
    node2->setVal(3);
    pointerToHead.insertNode(*node2, 2);
    pointerToHead.printList();
    pointerToHead.deleteNode(1);
    pointerToHead.printList();
    std::cout << "3" << std::endl << std::endl;

//    Node* node2 = new Node;
//    node2->setVal(3);
//    pointerToHead.insertNode(*node2, 2);
//    pointerToHead.printList();
//    pointerToHead.deleteNode(2);
//    pointerToHead.printList();
//    std::cout << "3" << std::endl << std::endl;


    delete node2;
    delete node1;
    delete head;














    /* code from before */
    /* don't mind it */


//    LinkedList pointerToHead;
//    Node head(7);
//
//    pointerToHead.insertNode(head, 0);
//    pointerToHead.printList();
//    std::cout << "hi1" << std::endl;
//
//    Node node1(8);
//    pointerToHead.insertNode(node1, 1);
//    pointerToHead.printList();
//    std::cout << "hi2" << std::endl;
//
//    Node node2(9);
//    pointerToHead.insertNode(node2, 2);
//    pointerToHead.printList();
//    std::cout << "hi3" << std::endl;
//
////    pointerToHead.deleteNode(0);
////    pointerToHead.printList();
////    std::cout << "hi4" << std::endl;
//
////    pointerToHead.deleteNode(1);
////    pointerToHead.printList();
////    std::cout << "hi4" << std::endl;
//
////    pointerToHead.deleteNode(2);
////    pointerToHead.printList();
////    std::cout << "hi4" << std::endl;
//
////    delete &head;
////    delete &node1;

    return 0;
}
