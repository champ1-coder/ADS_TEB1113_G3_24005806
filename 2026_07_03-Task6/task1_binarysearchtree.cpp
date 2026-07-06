// binarysearchtree

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) : name(n), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // insertion
    Node* insertRec(Node* node, const string& name) {
        if (node == nullptr) {
            return new Node(name);
        }
        if (name < node->name) {
            node->left = insertRec(node->left, name);
        } else if (name > node->name) {
            node->right = insertRec(node->right, name);
        } else {
            cout << "Duplicate name '" << name << "' ignored." << endl;
        }
        return node;
    }

    // Search
    bool searchRec(Node* node, const string& name) const {
        if (node == nullptr) return false;
        if (node->name == name) return true;
        if (name < node->name) return searchRec(node->left, name);
        return searchRec(node->right, name);
    }

    // ----- Find minimum node -----
    Node* minValueNode(Node* node) const {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // ----- deletion -----
    Node* deleteRec(Node* node, const string& name) {
        if (node == nullptr) {
            cout << name << " not found." << endl;
            return nullptr;
        }

        if (name < node->name) {
            node->left = deleteRec(node->left, name);
        } else if (name > node->name) {
            node->right = deleteRec(node->right, name);
        } else {
            // Found the node to delete
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node has two children – use in‑order successor
            Node* temp = minValueNode(node->right);
            node->name = temp->name;               // Copy successor's data
            node->right = deleteRec(node->right, temp->name); // Delete successor
        }
        return node;
    }

    // ----- In‑order (ascending) -----
    void inorderRec(Node* node) const {
        if (node == nullptr) return;
        inorderRec(node->left);
        cout << node->name << endl;
        inorderRec(node->right);
    }

    // Reverse in‑order (descending)
    void reverseInorderRec(Node* node) const {
        if (node == nullptr) return;
        reverseInorderRec(node->right);
        cout << node->name << endl;
        reverseInorderRec(node->left);
    }

public:
    BST() : root(nullptr) {}

    // insertEnd
    void insertEnd(const string& name) {
        root = insertRec(root, name);
    }

    // insertAfter
    void insertAfter(const string& afterName, const string& newName) {
        if (!searchRec(root, afterName)) {
            cout << afterName << " not found." << endl;
            return;
        }
        root = insertRec(root, newName);
    }

    // deleteByName
    void deleteByName(const string& name) {
        root = deleteRec(root, name);
    }

    // display (in‑order = ascending alphabetical)
    void display() const {
        if (root == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        inorderRec(root);
    }

    // displayReverse (reverse in‑order = descending alphabetical)
    void displayReverse() const {
        if (root == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        reverseInorderRec(root);
    }
};


int main() {
    BST list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "\nInitial list (alphabetical order):" << endl;
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

    cout << "\nReverse list (descending alphabetical):" << endl;
    list.displayReverse();

    cout << "\nFinal list (alphabetical):" << endl;
    list.display();

    return 0;
}