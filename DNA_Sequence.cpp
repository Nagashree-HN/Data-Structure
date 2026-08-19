#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// Helper function to handle the custom DNA substitution costs
int getSubCost(char a, char b) {
    if (a == b) return 0; // Match
    
    // Allowed Mismatches (Cost 1)
    if ((a == 'A' && b == 'G') || (a == 'G' && b == 'A')) return 1;
    if ((a == 'T' && b == 'C') || (a == 'C' && b == 'T')) return 1;
    
    // Heavy Mismatches (Cost 5)
    return 5; 
}

// Function to read DNA sequence from a file and strip newlines/spaces
string readSequence(const string& filename) {
    ifstream file(filename);
    string sequence = "";
    string line;
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return "";
    }

    while (getline(file, line)) {
        for (char c : line) {
            // Keep only valid DNA characters
            if (c == 'A' || c == 'G' || c == 'T' || c == 'C') {
                sequence += c;
            }
        }
    }
    file.close();
    return sequence;
}

// PART D: Space-Optimized Sequence Alignment Algorithm
int spaceOptimizedAlignment(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    int gapCost = 1;

    // Optimization: Ensure we use the smaller sequence for our 1D array size
    // to strictly enforce the smallest possible linear space O(min(m, n))
    if (m < n) {
        swap(X, Y);
        swap(m, n);
    }

    // Instead of an (m+1) x (n+1) matrix, we only keep 2 rows of size (n+1)
    vector<int> prevRow(n + 1);
    vector<int> currRow(n + 1);

    // Initialize the base case for the first row (analogous to the top row of the matrix)
    for (int j = 0; j <= n; j++) {
        prevRow[j] = j * gapCost;
    }

    // Iterate through sequence X (representing rows)
    for (int i = 1; i <= m; i++) {
        // Base case for the current row's first column (analogous to the leftmost column)
        currRow[0] = i * gapCost;

        // Iterate through sequence Y (representing columns)
        for (int j = 1; j <= n; j++) {
            
            // Calculate the three possible operations
            int matchOrSub = prevRow[j - 1] + getSubCost(X[i - 1], Y[j - 1]);
            int deleteOp   = prevRow[j] + gapCost;
            int insertOp   = currRow[j - 1] + gapCost;

            // Take the minimum cost
            currRow[j] = min({matchOrSub, deleteOp, insertOp});
        }

        // The current row becomes the previous row for the next iteration
        prevRow = currRow;
    }

    // The final optimal alignment cost is in the last cell of the retained row
    return prevRow[n];
}

int main() {
	
	
	/*string X, Y;
    cout << "Enter sequence X: ";
    cin >> X;
    cout << "Enter sequence Y: ";
    cin >> Y; */
    // 1. Read the sequences from the provided files
    cout << "Reading files..." << endl;
    string humanDNA = readSequence("C:\\Users\\nagas\\OneDrive\\Documents\\DSA\\humans.txt");
    string mouseDNA = readSequence("C:\\Users\\nagas\\OneDrive\\Documents\\DSA\\mice.txt");

    if (humanDNA.empty() || mouseDNA.empty()) {
        cout << "Failed to load sequences. Please check file paths." << endl;
        return 1;
    }

    cout << "Human DNA Length: " << humanDNA.length() << " bases." << endl;
    cout << "Mouse DNA Length: " << mouseDNA.length() << " bases." << endl;

    // 2. Run the space-optimized algorithm
    cout << "\nCalculating optimal alignment cost (this may take a moment)..." << endl;
    int optimalCost = spaceOptimizedAlignment(humanDNA, mouseDNA);

    // 3. Output the result
    cout << "--------------------------------------" << endl;
    cout << "Optimal Alignment Cost: " << optimalCost << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}