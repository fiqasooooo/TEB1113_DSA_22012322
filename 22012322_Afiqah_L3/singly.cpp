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

    Node(string n) {
        name = n;
        next = NULL;
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
            tail = newNode;
        }
    }

    void display_list() {
        Node* current = head;
        cout << "List: ";
        while (current != NULL) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void delete_node(string value) {
        if (head == NULL) return;

        if (head->name == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == NULL) tail = NULL; 
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->name != value) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "Node with value \"" << value << "\" not found.\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) tail = current; 
        delete temp;
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

