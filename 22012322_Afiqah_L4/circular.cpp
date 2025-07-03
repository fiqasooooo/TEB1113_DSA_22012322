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
    Node(string name) : name(name) , next(NULL) {}

    

};

class CircularLinkedList {
public:

string name;
Node* head = NULL;
Node* tails = NULL;

    void addNode(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = newNode;
            tails = newNode;
            newNode->next = head; 
        } else {
            tails->next = newNode;
            tails = newNode;
            tails->next = head; 
        }
    }

    void display() {
        Node* current = head;

       do {
        cout << current->name << "-> ";
        current = current->next;
    } while (current != head);
cout << current->name << endl;

}
};

int main() {


CircularLinkedList cll;

cll.addNode("Ali");
cll.addNode("Ahmed"); 
cll.addNode("Alice");
cll.addNode("Hamza");

cll.display();


    return 0;

}
