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
    Node(int value);

    /* *************************** */
    /* *****THE RULE OF THREE***** */
    /* *************************** */
    ~Node();
    Node(const Node& originalNode);
    Node& operator=(const Node& originalNode);

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
     */

    int value = 0;
    Node* next = nullptr;
};

/* ****************************** */
/* ******CLASS: LINKED LIST****** */
/* ****************************** */

#endif //LINKEDLISTSPRACTICE_LINKEDLIST_H
