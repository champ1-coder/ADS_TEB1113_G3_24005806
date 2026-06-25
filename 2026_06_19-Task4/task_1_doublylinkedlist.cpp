//task 4 husna double linked list

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
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << afterName << " not found." << endl;
            return;
        }
        Node* newNode = new Node(newName);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    void deleteByName(string name) {
        if (head == nullptr) return;
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = current;
                }
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
        while (current != nullptr) {  // stops at nullptr
            cout << current->name << endl;
            current = current->next;
        }
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;  // walk to tail
        }
        while (current != nullptr) {  // walk back via prev
            cout << current->name << endl;
            current = current->prev;
        }
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