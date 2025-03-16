#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Include this header for reverse function
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(const string& X, const string& Y, int m, int n) {
    // Create a 2D DP table to store the lengths of longest common subsequence
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // If characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // If characters don't match
            }
        }
    }

    // Return the length of the LCS
    return dp[m][n];
}

// Function to construct the LCS string from the dp table
string constructLCS(const string& X, const string& Y, const vector<vector<int> >& dp, int m, int n) {
    string lcsStr;
    int i = m, j = n;

    // Trace back the LCS from the dp table
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr.push_back(X[i - 1]);  // If characters match, add to LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;  // Move up if the previous row has a greater value
        } else {
            j--;  // Move left if the previous column has a greater value
        }
    }

    // Reverse the LCS as we built it backward
    reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

int main() {
    string X, Y;

    // Ask user for the two strings
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    // Call the LCS function to get the length of the LCS
    int length = lcs(X, Y, m, n);
    cout << "Length of Longest Common Subsequence: " << length << endl;

    // Construct and print the LCS
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    lcs(X, Y, m, n);  // Fill dp table
    string lcsStr = constructLCS(X, Y, dp, m, n);
    cout << "Longest Common Subsequence: " << lcsStr << endl;

    return 0;
}

