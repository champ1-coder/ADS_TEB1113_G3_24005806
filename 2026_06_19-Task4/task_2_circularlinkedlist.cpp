//task 4 husna circular linked list

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertEnd(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;  // points to itself
            newNode->prev = newNode;
            return;
        }
        Node* tail = head->prev;  // tail is always head->prev in circular
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;
        while (current->name != afterName) {
            current = current->next;
            if (current == head) {  // full loop, not found
                cout << afterName << " not found." << endl;
                return;
            }
        }
        Node* newNode = new Node(newName);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;  // always valid, no nullptr in circular
        current->next = newNode;
    }

    void deleteByName(string name) {
        if (head == nullptr) return;

        // single node
        if (head->next == head) {
            if (head->name == name) {
                delete head;
                head = nullptr;
            }
            return;
        }

        // deleting head
        if (head->name == name) {
            Node* tail = head->prev;
            Node* newHead = head->next;
            tail->next = newHead;   // tail points to new head
            newHead->prev = tail;   // new head points back to tail
            delete head;
            head = newHead;
            return;
        }

        // deleting any other node
        Node* current = head;
        do {
            if (current->next->name == name) {
                Node* temp = current->next;
                current->next = temp->next;
                temp->next->prev = current;
                delete temp;
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head);  // stops when back at head
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* current = head->prev;  // start at tail directly
        do {
            cout << current->name << endl;
            current = current->prev;
        } while (current != head->prev);  // stops when back at tail
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "\nInitial list:" << endl;
    list.display();

    cout << "\nAfter inserting Ali after Anjana:" << endl;
    list.insertAfter("Anjana", "Ali");
    list.display();

    cout << "\nAfter inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();

    cout << "\nAfter deleting Jessy:" << endl;
    list.deleteByName("Jessy");
    list.display();

    cout << "\nReverse list:" << endl;
    list.displayReverse();

    cout << "\nFinal list (in order):" << endl;
    list.display();
}