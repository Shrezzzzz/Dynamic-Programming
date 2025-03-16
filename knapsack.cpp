#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP table
    vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // If the item can be included
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                // If the item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right cell contains the maximum value
    return dp[n][W];
}

int main() {
    int n, W;

    // Ask the user for the number of items and the capacity of the knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    if (n <= 0) {
        cout << "Number of items must be greater than 0.\n";
        return 1;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    if (W <= 0) {
        cout << "Capacity of the knapsack must be greater than 0.\n";
        return 1;
    }

    vector<int> weights(n), values(n);

    // Ask the user to input the weight and value of each item
    cout << "Enter the weights and values of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weights[i];
        if (weights[i] < 0) {
            cout << "Weight cannot be negative. Exiting.\n";
            return 1;
        }

        cout << "Item " << i + 1 << " - Value: ";
        cin >> values[i];
        if (values[i] < 0) {
            cout << "Value cannot be negative. Exiting.\n";
            return 1;
        }
    }

    // Call knapsack function to compute the maximum value
    int maxValue = knapsack(W, weights, values, n);

    // Output the result
    cout << "The maximum value that can be carried in the knapsack is: " << maxValue << endl;

    return 0;
}

