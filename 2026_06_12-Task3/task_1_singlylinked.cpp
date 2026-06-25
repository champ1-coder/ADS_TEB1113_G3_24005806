//task 3 husna

singly linked fixed

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
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
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }
        if (current == nullptr) {
            // FIX: added space before "not found"
            cout << afterName << " not found." << endl;
            return;
        }
        Node* newNode = new Node(newName);
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteByName(string name) {
        if (head == nullptr) return;
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    list.insertAfter("Anjana", "Ali");
    list.insertEnd("Jane");
    list.deleteByName("Jessy");

    cout << "\nFinal list:" << endl;
    list.display();

    return 0;
}