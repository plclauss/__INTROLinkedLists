//
// Created by plcla on 4/5/2022.
//

#include "LinkedList.h"
#include <iostream>
#include <cassert>

/* *********************** */
/* ******CLASS: NODE****** */
/* *********************** */
// Constructors + Big Three
Node::Node() {
    this->next = nullptr;
    this->value = 0;
}

Node::Node(int value) {
    this->next = nullptr;
    this->value = value;
}

Node::Node(const Node &originalNode) {
    next = new Node;
    next = originalNode.next;

    value = originalNode.value;
}

Node& Node::operator=(const Node &originalNode) {
    if (this != &originalNode) {
        delete next;
        next = new Node;
        *next = *originalNode.next;

        value = originalNode.value;
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

void Node::setAddress(Node& node) {
    if (this->next == nullptr)
        this->next = new Node;
    this->next = &node;
}

/* ****************************** */
/* ******CLASS: LINKED LIST****** */
/* ****************************** */
// Constructors + Big Three
LinkedList::LinkedList() {
    this->head = nullptr;
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
    Node* listCopy = head;
    int counter = 0;

    while (listCopy) {
        if (counter == endValue)
            break;

        listCopy = listCopy->getAddressOfNextNode();
        counter++;
    }

    return *listCopy;
}

int LinkedList::getLengthOfList() {
    Node* listCopy = head;
    int len = 1;

    while (listCopy->getAddressOfNextNode() != nullptr) {
        len++;
        listCopy = listCopy->getAddressOfNextNode();
    }

    return len;
}

void LinkedList::insertNode(Node& nodeToInsert, int index) {
    if (index == 0) {
        head = &nodeToInsert;
        return;
    }

    const int length = getLengthOfList();
    assert((index <= length) && (index >= 0));

    nodeToInsert.setAddress(traverseList(index));
    traverseList(index - 1).setAddress(nodeToInsert);
}

void LinkedList::deleteNode(int index) {
    if (index == 0) {
        Node* tempNextNode = head->getAddressOfNextNode();
        head = tempNextNode;
        return;
    }

    const int length = getLengthOfList();
    assert((index < length) && (index >= 0));

    traverseList(index - 1).setAddress(traverseList(index + 1));
}

void LinkedList::printList() {
    Node* copyLinkedList = head;

    while (copyLinkedList) {
        std::cout << copyLinkedList->getVal() << " --> ";
        copyLinkedList = copyLinkedList->getAddressOfNextNode();
    }
    std::cout << std::endl;
}
