#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP

#include "LinkedList.hpp"
#include <string>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem);

    if (this->head == nullptr) {
        this->head = newNode;
    } 
    else {
        Node* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    this->length++;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw std::string("Error: getElement() position is out of bounds.");
    }

    Node* current = this->head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->value;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw std::string("Error: replace() position is out of bounds.");
    }
    
    Node* current = this->head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    current->value = elem;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw std::string("Error: insert() position is out of bounds.");
    }

    Node* newNode = new Node(elem);

    if (position == 0) {
        newNode->next = this->head;
        this->head = newNode;
    } 
    else {
        Node* current = this->head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (isEmpty() || position < 0 || position >= this->length) {
        throw std::string("Error: remove() position is out of bounds or list is empty.");
    }

    Node* nodeToDelete = nullptr;

    if (position == 0) {
        nodeToDelete = this->head;
        this->head = this->head->next;
    } 
    else {
        Node* current = this->head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        nodeToDelete = current->next;
        current->next = nodeToDelete->next;
    }

    delete nodeToDelete;
    this->length--;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* current = this->head;
    while (current != nullptr) {
        Node* nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
    }
    this->head = nullptr;
    this->length = 0;
}

template <typename U>
ostream& operator<<(ostream& outStream, const LinkedList<U>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    } 
    else {
        typename LinkedList<U>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }
    return outStream;
}

#endif

