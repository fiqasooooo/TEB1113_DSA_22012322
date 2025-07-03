/*
ID = 22012322
Name = Nur Afiqah Solehah binti Mazlan 
Lab = G3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<int> elements;
    elements.reserve(m * n);

    // Prompt the user to enter each element
    cout << "Enter the matrix elements, row by row:\n";
    for (int i = 0; i < m * n; i++) {
        int x;
        cin >> x;
        elements.push_back(x);
    }

    // Sort all values
    sort(elements.begin(), elements.end());

    // Write them back into a matrix structure
    vector<vector<int> > matrix(m, vector<int>(n));
    int idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = elements[idx++];
        }
    }

    // Print the rearranged matrix
    cout << "\nMatrix in strict sorted order:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

