#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    private:
        T obj;
        Node<T>* next;

    public:
        Node();
        Node(const T& entry);
        Node(const T& entry, Node<T>* nextPtr);
        Node(const Node<T>& other); //copy constructor will recursively make a deep copy on each node. We don't want double deletes.
        ~Node();
        bool isLeaf() const;
        int getLength() const;
        Node<T>* getEnd() const;
        Node<T>* nodeAt(int index) const;
        T getItem() const;
        void setItem(const T& item);
        Node<T>* getNext() const;
        void setNext(Node<T>* nextPtr);
        Node<T>& operator=(const Node<T>& other); // when this node re-assigns itself as pre-existing node => use deep copy semantics
};


// This function used to both nullify the node's next ptr and then delete the node
// CAREFUL: Ensure that you make something reference the node's initial next ptr before calling this, otherwise memory leak
template <typename T>
void deleteNode(Node<T>* n) {
    n->setNext(nullptr);
    delete n;
}

#endif