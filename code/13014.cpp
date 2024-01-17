// WA 2/10
#include <iostream>
#include <vector>

using namespace std;

// Function to check whether it's possible to make A into B in at most K operations
bool isPossible(vector<string>& A, vector<string>& B, int K) {
    int countX_A = 0, countX_B = 0;  // Count of 'x' cells in A and B

    // Check if both boards have the same number of 'x' cells
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == 'x') countX_A++;
            if (B[i][j] == 'x') countX_B++;
        }
    }

    // If the counts are not equal, it's not possible
    if (countX_A != countX_B) return false;

    // Iterate through the cells and check the Manhattan distance between 'x' cells
    int distance = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == 'x') {
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        if (B[ii][jj] == 'x') {
                            distance += abs(i - ii) + abs(j - jj);
                        }
                    }
                }
            }
        }
    }

    // Check if the distance is less than or equal to K
    return distance <= K;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        vector<string> A(3);
        vector<string> B(3);

        // Input the 8-puzzle boards A and B
        for (int i = 0; i < 3; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < 3; i++) {
            cin >> B[i];
        }

        // Check if it's possible to make A into B in at most K operations
        if (isPossible(A, B, K)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
