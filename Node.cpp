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

}

template <typename T>
Node<T>::~Node<T>() {
    if(!isLeaf()) delete next;
}

template <typename T>
bool Node<T>::isLeaf() const {

}

template <typename T>
int Node<T>::getLength() const {

}

template <typename T>
Node<T>* Node<T>::getEnd() const {

}

template <typename T>
Node<T>* Node<T>::nodeAt(int index) const {

}

template <typename T>
T Node<T>::getItem() const {

}

template <typename T>
void Node<T>::setItem(const T& item) {

}

template <typename T>
Node<T>* Node<T>::getNext() const {

}

template <typename T>
void Node<T>::setNext(Node<T>* nextPtr) {

}