//
// Created by plcla on 4/5/2022.
//

#ifndef LINKEDLISTSPRACTICE_LINKEDLIST_H
#define LINKEDLISTSPRACTICE_LINKEDLIST_H

/* *********************** */
/* ******CLASS: NODE****** */
/* *********************** */

class Node {
public:
    Node();
    Node(int value);

    /* *************************** */
    /* *****THE RULE OF THREE***** */
    /* *************************** */
//    ~Node();
    Node(const Node& originalNode);
    Node& operator=(const Node& originalNode);

    /* ************************** */
    /* *****CUSTOM FUNCTIONS***** */
    /* ************************** */
    int getVal();
    void setVal(int value);
    Node* getAddressOfNextNode();
    void setAddress(Node& node);

private:
    /*
     * At its base, a node within a linked list carries two items:
     *  (1) a value you wish to store, and
     *  (2) some way to get to the next node in the list, typically a pointer.
     * We will be employing this stereotype.
     *
     * However, when initializing a node, we will be using the 'new' keyword.
     * Thus, it's important to have a destructor for this class, which implies
     * at least two things:
     *  (1) If we're including a destructor, it's generally good practice to
     *  also include a copy constructor and a copy assignment operator, and
     *  (2) When initializing a linked list, we must pass it a pointer to a node,
     *  and not the node itself.
     *
     */

    int value = 0;
    Node* next = nullptr;
};

/* ****************************** */
/* ******CLASS: LINKED LIST****** */
/* ****************************** */
class LinkedList {
public:
    /*
     * Note: We could do an inline definition, but all of these function
     * definitions are held within the LinkedList.cpp file. This file plays
     * the role of being handed to a client. They don't need to know exactly
     * how everything works; they just need to know what functions are available
     * to them.
     *
     * This class still requires a constructor, though. Just one, in case the
     * linked list is defined first. The linked list is made up of nodes, so
     * we only have the one constructor here. Everything else may be done with
     * the Node class. (Except for the linked list functions, which will be
     * implemented here, like traversal and insert).
     */
    LinkedList();

    /* *************************** */
    /* *****THE RULE OF THREE***** */
    /* *************************** */
//    ~LinkedList();
    LinkedList(const LinkedList& originalLinkedList);
    LinkedList& operator=(const LinkedList& originalLinkedList);

    /* ************************** */
    /* *****CUSTOM FUNCTIONS***** */
    /* ************************** */
    Node& traverseList(int endValue);
    int getLengthOfList();
    void insertNode(Node& nodeToInsert, int index);
    void deleteNode(int index);
    void printList();

private:
    Node* head;
};

#endif //LINKEDLISTSPRACTICE_LINKEDLIST_H
