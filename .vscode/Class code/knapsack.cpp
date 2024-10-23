#include <iostream>
#include <vector>
#include <algorithm>  // For std::max

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(const vector<int>& weights, const vector<int>& values, int W) {
    int n = weights.size();  // Number of items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));  // DP table

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Include the item or exclude it, and take the maximum value
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The answer will be in dp[n][W]
    return dp[n][W];
}

int main() {
    int n, W;

    // Input the number of items and the maximum weight capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    // Initialize vectors for weights and values
    vector<int> weights(n);
    vector<int> values(n);

    // Input weights
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    // Input values
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Call the knapsack function
    int maxValue = knapsack(weights, values, W);

    // Output the result
    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
