//
// Created by plcla on 4/5/2022.
//

#include "LinkedList.h"
#include <cassert>

/* *********************** */
/* ******CLASS: NODE****** */
/* *********************** */
// Constructors + Big Three
Node::Node() {
    this->value = 0;
    this->next = nullptr;
}

Node::Node(int value) {
    this->value = value;
}

Node::~Node() {
    delete this;
}

Node::Node(const Node &originalNode) {
    this->next = new Node;
    this->next = originalNode.next;

    this->value = originalNode.value;
}

Node& Node::operator=(const Node &originalNode) {
    if (this != &originalNode) {
        delete this->next;
        this->next = new Node;
        this->next = originalNode.next;
//        *next = *originalNode.next;

        this->value = originalNode.value;
    }

    return *this;
}

// Custom Functions
int Node::getVal() {
    return this->value;
}

void Node::setVal(int value) {
    this->value = value;
}

Node* Node::getAddressOfNextNode() {
    return this->next;
}

void Node::setAddress(Node node) {
    this->next = &node;
}

/* ****************************** */
/* ******CLASS: LINKED LIST****** */
/* ****************************** */
// Constructors + Big Three
LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* nextNode = head->getAddressOfNextNode();
        delete this->head;
        this->head = nextNode;
    }
}

LinkedList::LinkedList(const LinkedList &originalLinkedList) {
    this->head = new Node;
    this->head->setVal(originalLinkedList.head->getVal());
    this->head->setAddress(*originalLinkedList.head->getAddressOfNextNode());
}

LinkedList &LinkedList::operator=(const LinkedList &originalLinkedList) {
    if (this != &originalLinkedList) {
        delete this->head;
        this->head = new Node;
        this->head->setVal(originalLinkedList.head->getVal());
        this->head->setAddress(*originalLinkedList.head->getAddressOfNextNode());
    }

    return *this;
}

// Custom Functions
Node& LinkedList::traverseList(int endValue) {
    int counter = 0;
    while (head) {
        if (counter == endValue)
            break;

        head = head->getAddressOfNextNode();
        counter++;
    }

    return *head;
}

int LinkedList::getLengthOfList() {
    int len = 0;
    while (head) {
        len++;
        head = head->getAddressOfNextNode();
    }

    return len;
}

void LinkedList::insertNode(Node nodeToInsert, int index) {
    if (index == 0) {
        nodeToInsert.setAddress(*head);
        return;
    }

    const int length = getLengthOfList();
    assert((index < length) && (index >= 0));

    nodeToInsert.setAddress(traverseList(index));
    traverseList(index - 1).setAddress(nodeToInsert);
}

void LinkedList::deleteNode(int index) {
    if (index == 0) {
        Node* tempNextNode = head->getAddressOfNextNode();
        delete head;
        head = tempNextNode;
        return;
    }

    const int length = getLengthOfList();
    assert((index < length) && (index >= 0));

    traverseList(index - 1).setAddress(traverseList(index));
    delete &traverseList(index);
}