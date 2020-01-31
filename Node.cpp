#include "Node.h"

template <typename T>
Node<T>::Node<T>(const T& entry) {
    obj = entry;
    next = nullptr;
}

template <typename T>
Node<T>::Node<T>(const T& entry, Node<T>* nextPtr) {
    obj = entry; // Assume overloaded equality operator on type T
    next = nextPtr;
}

template <typename T>
Node<T>::Node<T>(const Node<T>& other) {
    obj = other.obj;
    next = other.isLeaf() ? nullptr : new Node<T>(*other.next);
}

template <typename T>
Node<T>::~Node<T>() {
    if(!isLeaf()) delete next;
}

template <typename T>
bool Node<T>::isLeaf() const {
    return(next == nullptr);
}

template <typename T>
int Node<T>::getLength() const {
    return(isLeaf() ? 1 : 1 + next->getLength());
}

template <typename T>
Node<T>* Node<T>::getEnd() const {
    return(isLeaf() ? this : next->getEnd());
}

template <typename T>
Node<T>* Node<T>::nodeAt(int index) const {
    if(index < 1) {
        throw(std::runtime_error("List index provided is too small. Method: 'nodeAt'.\n"));
    } else if(isLeaf() && index > 1) {
        throw(std::runtime_error("List index provided is too large. Method: 'nodeAt'.\n"));
    }

    return(index == 1 ? this : next->nodeAt(index - 1));
}

template <typename T>
T Node<T>::getItem() const {
    return obj;
}

template <typename T>
void Node<T>::setItem(const T& item) {
    obj = item;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T>* nextPtr) {
    next = nextPtr;
}

template <typename T>
void Node<T>::removeDuplicates() {
    if(isLeaf()) return;
    next->removeDuplicates();

    Node<T>* p = this;
    Node<T>* t = next;
    while(t != nullptr) {
        if(t->obj == obj) {
            p->next = t->next;
            deleteNode(t);
            t = p->next;
        } else {
            p = t;
            t = t->next;
        }
    }
}