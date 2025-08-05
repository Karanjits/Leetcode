#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Node structure
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

// Singly Linked List class
class LinkedList {
private:
    ListNode* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Insert at end
    void append(int value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Insert at front
    void prepend(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at given index
    void insertAt(int index, int value) {
        if (index < 0) return;

        if (index == 0) {
            prepend(value);
            return;
        }

        ListNode* newNode = new ListNode(value);
        ListNode* current = head;
        for (int i = 0; current && i < index - 1; ++i) {
            current = current->next;
        }

        if (!current) return;

        newNode->next = current->next;
        current->next = newNode;
    }

    // Delete first node with given value
    void deleteValue(int value) {
        if (!head) return;

        if (head->val == value) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* current = head;
        while (current->next && current->next->val != value) {
            current = current->next;
        }

        if (current->next) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Delete at index
    void deleteAt(int index) {
        if (index < 0 || !head) return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* current = head;
        for (int i = 0; current->next && i < index - 1; ++i) {
            current = current->next;
        }

        if (current->next) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Get value at index
    int getAt(int index) const {
        ListNode* current = head;
        for (int i = 0; current && i < index; ++i) {
            current = current->next;
        }
        if (current)
            return current->val;
        throw out_of_range("Index out of range");
    }

    // Get size of list
    int size() const {
        int count = 0;
        ListNode* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    // Search for value
    bool contains(int value) const {
        ListNode* current = head;
        while (current) {
            if (current->val == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // Print the list
    void print() const {
        ListNode* current = head;
        while (current) {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }

    // Clear the entire list
    void clear() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif // LINKEDLIST_H
