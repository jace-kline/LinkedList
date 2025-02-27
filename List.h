#ifndef LIST_H
#define LIST_H

#include "ListInterface.h"
#include "Node.h"

template <typename T>
class List : ListInterface<T> {
    private:
        Node<T>* headPtr;
    
    public:
        List<T>();
        List<T>(const List<T>& other); // deep copy constructor
        ~List<T>();
        bool isEmpty() const;
        int getLength() const;
        bool contains(const T& obj) const;
        void insertFront(const T& obj);
        T getFront() throw(std::runtime_error);
        void insertEnd(const T& obj);
        T getEnd() throw(std::runtime_error);
        void insertAt(const T& obj, int pos) throw(std::runtime_error);
        void remove(int pos) throw (std::runtime_error);
        bool removeObj(const T& obj); // removes last instance of matching item in list
        void removeDuplicates();
        void clear();
        T getEntry(int pos) const throw (std::runtime_error);
        void replace(int position, T obj) throw (std::runtime_error);
        void reverse(); // in place reverse
        Node<T>* head();
        Node<T>* nodeFromItem(const T& entry);
        List<T>& operator=(const List<T>& other);
        void traverse(void (*eff)(const T& val));
};

template <typename T>
List<T> reverse(const List<T>& l); // copied reverse function -> don't mutate original list

#endif