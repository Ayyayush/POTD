#include <bits/stdc++.h>
using namespace std;

/*
 * 🔴 Brute Force Approach
 * -----------------------
 * Time Complexity  : O(N^2)       // For each person, we check if they are known by all and know no one
 * Space Complexity : O(1)         // No extra space
 */
void brute(vector<vector<int>>& M) {
    int n = M.size();
    int celebrity = -1;

    for (int i = 0; i < n; i++) {
        bool knowsSomeone = false;
        bool knownByAll   = true;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if (M[i][j] == 1) {
                /*
                 * If person i knows someone, then he cannot be celebrity
                 */
                knowsSomeone = true;
            }

            if (M[j][i] == 0) {
                /*
                 * If person i is not known by someone, he cannot be celebrity
                 */
                knownByAll = false;
            }
        }

        if (!knowsSomeone && knownByAll) {
            celebrity = i;
            break;
        }
    }

    cout << "🔴 Brute Celebrity Index: " << celebrity << endl;
}

/*
 * 🟡 Better/Optimized Approach (Using Stack Elimination)
 * -------------------------------------------------------
 * Time Complexity  : O(N)        // Only one pass to find candidate, one pass to verify
 * Space Complexity : O(1)        // Constant space (no stack used, only variables)
 */
void better(vector<vector<int>>& M) {
    int n = M.size();
    int candidate = 0;

    /*
     * Step 1: Find a potential celebrity
     */
    for (int i = 1; i < n; i++) {
        if (M[candidate][i] == 1) {
            /*
             * If candidate knows i, then candidate can't be celebrity
             * But i can be, so update candidate
             */
            candidate = i;
        }
        // else candidate doesn't know i → i can't be celebrity, continue
    }

    /*
     * Step 2: Verify the candidate
     */
    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;

        if (M[candidate][i] == 1 || M[i][candidate] == 0) {
            /*
             * If candidate knows anyone → not a celebrity
             * OR if someone doesn't know candidate → not a celebrity
             */
            cout << "🟡 Better Celebrity Index: -1" << endl;
            return;
        }
    }

    cout << "🟡 Better Celebrity Index: " << candidate << endl;
}

/*
 * 🔵 Main function to run both approaches
 */
int main() {
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    brute(M);     // 🔴 Brute force approach
    better(M);    // 🟡 Optimized 2-pass approach

    return 0;
}
