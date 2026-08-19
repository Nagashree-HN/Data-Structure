#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to handle the custom DNA substitution costs from the image
int getSubCost(char a, char b) {
    if (a == b) return 0; // Match
    // Allowed Mismatches (Cost 1)
    if ((a == 'A' && b == 'G') || (a == 'G' && b == 'A')) return 1;
    if ((a == 'T' && b == 'C') || (a == 'C' && b == 'T')) return 1;
    // Heavy Mismatches (Cost 5)
    return 5; 
}

void sequenceAlignment(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    int gapCost = 1;

    // ==========================================
    // PART B: Construct the DP Table in O(m*n)
    // ==========================================
    
    // Create a 2D vector of size (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Initialize base cases (first row and first column)
    for (int i = 0; i <= m; i++) dp[i][0] = i * gapCost;
    for (int j = 0; j <= n; j++) dp[0][j] = j * gapCost;

    // Fill the table one row at a time
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int matchOrSub = dp[i - 1][j - 1] + getSubCost(X[i - 1], Y[j - 1]);
            int deleteOp   = dp[i - 1][j] + gapCost;
            int insertOp   = dp[i][j - 1] + gapCost;

            dp[i][j] = min({matchOrSub, deleteOp, insertOp});
        }
    }

    int optimalCost = dp[m][n];

    // ==========================================
    // PART C: Traceback for the Actual Alignment
    // ==========================================
    
    string alignX = "";
    string alignY = "";
    
    int i = m;
    int j = n;

    while (i > 0 || j > 0) {
        // Option 1: Came from diagonal (Match or Substitution)
        if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + getSubCost(X[i - 1], Y[j - 1])) {
            alignX += X[i - 1];
            alignY += Y[j - 1];
            i--;
            j--;
        }
        // Option 2: Came from top (Deletion -> Gap in Y)
        else if (i > 0 && dp[i][j] == dp[i - 1][j] + gapCost) {
            alignX += X[i - 1];
            alignY += '-';
            i--;
        }
        // Option 3: Came from left (Insertion -> Gap in X)
        else {
            alignX += '-';
            alignY += Y[j - 1];
            j--;
        }
    }

    // Since we traced backwards, we must reverse the strings
    reverse(alignX.begin(), alignX.end());
    reverse(alignY.begin(), alignY.end());

    // Print Results
    cout << "Optimal Alignment Cost: " << optimalCost << "\n\n";
    cout << "Actual Alignment:\n";
    cout << "Sequence X: " << alignX << "\n";
    cout << "Sequence Y: " << alignY << "\n";
}

int main() {
    // Testing with the strings from your assignment
    string X = "GTCC";
    string Y = "AGTTC";

    sequenceAlignment(X, Y);

    return 0;
}