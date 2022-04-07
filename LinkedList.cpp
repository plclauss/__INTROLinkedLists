//
// Created by plcla on 4/5/2022.
//

#include "LinkedList.h"

/* *********************** */
/* ******CLASS: NODE****** */
/* *********************** */
Node::Node(int value) {
    this->value = value;
}

Node::~Node() {
    delete this;
}

Node::Node(const Node &originalNode) {

}

/* ****************************** */
/* ******CLASS: LINKED LIST****** */
/* ****************************** */