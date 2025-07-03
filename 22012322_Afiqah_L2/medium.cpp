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
    int n, m;
    cout << "Enter number of rows (odd): ";
    cin >> n;
    cout << "Enter number of columns (odd): ";
    cin >> m;

    vector<vector<int> > mat(n, vector<int>(m));
    cout << "Enter the matrix elements row by row:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    // Step 1: Flatten the matrix
    vector<int> flat;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            flat.push_back(mat[i][j]);

    // Step 2: Sort
    sort(flat.begin(), flat.end());

    // Step 3: Get the median
    int median = flat[(n * m) / 2];  // middle index since total elements is odd

    cout << "Median of the matrix is: " << median << endl;
    return 0;
}

