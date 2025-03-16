#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to print the optimal parenthesization from the 's' table
void printOptimalParens(const vector<vector<int> >& s, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1;  // Print the matrix name
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// Function to find the minimum number of scalar multiplications for matrix chain multiplication
void matrixChainOrder(const vector<int>& dims, int n) {
    // m[i][j] will hold the minimum number of scalar multiplications needed to multiply matrix i through j
    vector<vector<int> > m(n, vector<int> (n, 0));
    
    // s[i][j] will hold the index of the matrix after which the optimal split occurs
    vector<vector<int> > s(n, vector<int> (n, 0));
    
    // l is the chain length
    for (int len = 2; len < n; len++) { // len starts from 2 to n-1
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            m[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i + 1; k < j; k++) {
                int q = m[i][k] + m[k][j] + dims[i] * dims[k] * dims[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print the optimal number of scalar multiplications
    cout << "Minimum number of scalar multiplications: " << m[0][n - 1] << endl;

    // Function to print the optimal parenthesization
    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 0, n - 1);
    cout << endl;
}

int main() {
    int n;

    // Ask user for the number of matrices
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> dims(n + 1);

    // Ask user to input the dimensions of the matrices (i.e., matrix[i] is dims[i-1] x dims[i])
    cout << "Enter the dimensions of the matrices (as an array of " << n + 1 << " integers): ";
    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    }

    // Call matrixChainOrder function to find the optimal parenthesization
    matrixChainOrder(dims, n + 1);

    return 0;
}

