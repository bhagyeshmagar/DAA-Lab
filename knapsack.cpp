#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    // Create a 2D table to store maximum values
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the table
    for (int i = 1; i <= n; i++) { // For each item
        for (int w = 0; w <= capacity; w++) { // For each possible weight
            if (weights[i - 1] <= w) {
                // If the item fits, choose the maximum between including or excluding it
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // If the item doesn't fit, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The answer is in the last cell of the table
    return dp[n][capacity];
}

int main() {
    // Example inputs
    vector<int> weights = {2, 3, 4, 5}; // Weights of items
    vector<int> values = {3, 4, 5, 6};  // Values of items
    int capacity = 5; // Maximum weight the knapsack can hold

    // Calculate the maximum value
    int max_value = knapsack(weights, values, capacity);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}