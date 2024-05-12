#include <iostream>

using namespace std;

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int w = 0; w <= W; ++w)
        dp[0][w] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    int n; 
    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n]; 
    int values[n];  

    cout << "Enter the weights of items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int maxValue = knapsack(W, weights, values, n);
    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}

