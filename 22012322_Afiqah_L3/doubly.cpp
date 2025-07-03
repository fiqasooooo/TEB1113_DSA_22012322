/*
ID = 22012322
Name = Nur Afiqah Solehah binti Mazlan 
Lab = G3
*/

#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert_node(Node* newNode) {
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;   
            newNode->prev = tail;   
            tail = newNode;         
        }
    }

    void display_list() {
        Node* current = head;
        cout << "List forward: ";
        while (current != NULL) {
            cout << current->name << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void display_backward() {
        Node* current = tail;
        cout << "List backward: ";
        while (current != NULL) {
            cout << current->name << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }

    void delete_node(string value) {
        if (head == NULL) return;

        Node* current = head;

        while (current != NULL && current->name != value) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Node with value \"" << value << "\" not found.\n";
            return;
        }

        if (current == head) head = head->next;
        if (current == tail) tail = tail->prev;

        if (current->prev != NULL)
            current->prev->next = current->next;

        if (current->next != NULL)
            current->next->prev = current->prev;

        delete current;
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Alice");
    Node* node3 = new Node("Ahmed");

    LinkedList std_names;
    std_names.insert_node(node1);
    std_names.insert_node(node2);
    std_names.insert_node(node3);

    cout << "Initial list:\n";
    std_names.display_list();

    cout << "\nDeleting node with name 'Alice':\n";
    std_names.delete_node("Alice");

    cout << "Updated list:\n";
    std_names.display_list();

    return 0;
}

