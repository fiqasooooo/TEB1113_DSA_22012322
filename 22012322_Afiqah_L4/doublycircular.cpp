/*
ID = 22012322
Name = Nur Afiqah Solehah binti Mazlan 
Lab = G3
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;

            newNode->next = head;
            head->prev = newNode;

            tail = newNode;
        }
    }

    void displayForward() {
        if (head == NULL) return;

        Node* current = head;
        cout << "Forward: ";
        do {
            cout << current->name << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head)" << endl;
    }

    void displayBackward() {
        if (tail == NULL) return;

        Node* current = tail;
        cout << "Backward: ";
        do {
            cout << current->name << " <-> ";
            current = current->prev;
        } while (current != tail);
        cout << "(back to tail)" << endl;
    }
};

int main() {
    DoublyCircularLinkedList cll;

    cll.addNode("Ali");
    cll.addNode("Ahmed");
    cll.addNode("Alice");
    cll.addNode("Hamza");
    

    cll.displayForward();
    cll.displayBackward();

    return 0;
}

