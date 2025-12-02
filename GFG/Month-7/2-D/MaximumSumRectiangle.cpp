#include <bits/stdc++.h>
using namespace std;

void generateAllSubmatrices() {
    int n = 3, m = 3;                                              // Hardcoded matrix dimensions
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };                                                              // Hardcoded 3x3 matrix

    // Generating all submatrices
    for(int row1 = 0; row1 < n; row1++) {
        for(int col1 = 0; col1 < m; col1++) {
            for(int row2 = row1; row2 < n; row2++) {
                for(int col2 = col1; col2 < m; col2++) {

                    // Print current submatrix
                    cout << "Submatrix from (" << row1 << "," << col1 << ") to (" << row2 << "," << col2 << "):\n";
                    for(int i = row1; i <= row2; i++) {
                        for(int j = col1; j <= col2; j++) {
                            cout << mat[i][j] << " ";
                        }
                        cout << "\n";
                    }
                    cout << "--------\n";
                }
            }
        }
    }

}


void generatemaxSum()
{
     int n = 3, m = 3;                                              // Hardcoded matrix dimensions
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };                                                              // Hardcoded 3x3 matrix

    int maxsum=INT_MIN,sum=0;

     // Generating all submatrices
    for(int row1 = 0; row1 < n; row1++) {
        for(int col1 = 0; col1 < m; col1++) {
            for(int row2 = row1; row2 < n; row2++) {
                for(int col2 = col1; col2 < m; col2++) {

                    // Print current submatrix
                   sum=0;
                    for(int i = row1; i <= row2; i++) {
                        for(int j = col1; j <= col2; j++) {
                          sum+=mat[i][j];
                        }
                        maxsum=max(sum,maxsum);
                    }
                   
                }
            }
        }
    }

    cout<<maxsum<<endl;
}



  /*
        Kadane's Algorithm:
        -------------------
        Ye function 1D array ka maximum sum subarray return karta hai.
        Basically, har index pe ye decide karta hai:
        - Kya is index se naya subarray start karein?
        - Ya previous subarray ko extend karein?

        Isme 2 cheezein track hoti hain:
        - max_ending_here → current subarray ka max sum
        - max_so_far → ab tak ka global max subarray sum
    */
  

   int kadanes(vector<int>& temp)
    {
        int currsum = temp[0];                          // Start with first element (even if negative)
        int maxsum = temp[0];                           // max also starts with first element

        for (int i = 1; i < temp.size(); i++)
        {
            currsum = max(temp[i], currsum + temp[i]);  // Either start new subarray or continue
            maxsum = max(maxsum, currsum);              // Update max so far
        }

        return maxsum;
    }


 void generatemaxSum_usingKadane()
{
    /**
     ** Approach
    /*
        maxRectSum:
        -----------
        Yeh function ek 2D matrix mein maximum sum rectangle (submatrix) ka sum return karta hai.

        🔍 Logic:
        --------
        - Hum har row-pair (top, bottom) fix karte hain.
        - Inke beech ki saari rows ko collapse karke ek 1D temp array banaate hain:
            temp[col] = sum of mat[top][col] to mat[bottom][col]
        - Phir is temp array par 1D Kadane apply karke max subarray sum nikaalte hain.
        - Yeh sum represent karta hai max rectangle between row 'top' and 'bottom'.

        ⚙️ Time Complexity:
        -------------------
        - Outer 2 loops: O(n²)
        - Inner Kadane (on m size array): O(m)
        - Total: O(n² * m) → Much better than O(n³ * m³)
    */
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();           // Number of rows
        int m = mat[0].size();        // Number of columns
        int maxSum = INT_MIN;         // Global max rectangle sum

        // Fix top row of rectangle
        for (int top = 0; top < n; top++) {
            vector<int> temp(m, 0);   // Temp array to store column-wise sum between rows [top...bottom]

            // Fix bottom row of rectangle
            for (int bottom = top; bottom < n; bottom++) {
                // Update temp with current row's values
                for (int col = 0; col < m; col++) {
                    temp[col] += mat[bottom][col];   // Add current row's values to temp (column-wise sum)
                }

                // Now, temp[] represents 1D array of column-sums from row 'top' to 'bottom'
                // Find maximum subarray sum using Kadane's algorithm
                int currMax = kadane(temp);

                // Update global max if current sum is higher
                maxSum = max(maxSum, currMax);
            }
        }

        return maxSum;
    }

}


int main() {
  //  generateAllSubmatrices();
    generatemaxSum();
    return 0;
}
