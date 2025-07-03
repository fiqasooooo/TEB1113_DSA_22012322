#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    int contact;
    string email ;
    
};

int main() {
    Student students[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for student " << i+1 << ":\n";
        cout << "Student Id: "; cin >> students[i].id;
        cout << "Name: "; cin >> students[i].name;
        cout << "Contact: "; cin >> students[i].contact;
        cout << "Email: "; cin >> students[i].email;
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < 5; i++) {
        cout <<  "Student Id: " << students[i].id
             << ", Name: " << students[i].name
             << ", Contact: " << students[i].contact
             << ", Email: " << students[i].email << endl;
    }
    return 0;
}

/*
ID = 22012322
Name = Nur Afiqah Solehah Binti Mazlan
 */



