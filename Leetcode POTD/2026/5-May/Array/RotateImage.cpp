#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ! APPROACH : Extra Matrix Rotation
    // ! T.C. : O(N*N)
    // ! S.C. : O(N*N)

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // ! Initialize temporary matrix
        vector<vector<int>> tempMatrix(n, vector<int>(n));

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                // ! Rotate 90 degree clockwise
                tempMatrix[col][n - 1 - row] = matrix[row][col];
            }
        }

        matrix = tempMatrix;
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // transpose and reverse
        int n=matrix.size();
    
        for(int i=0;i<n;i++)
        {
           
            for(int j=i;j<n;j++)
            {
             swap(matrix[i][j],matrix[j][i]);
            }

        }
        
     for(int i=0;i<n;i++)
     {
        reverse(matrix[i].begin(),matrix[i].end());
     }
    }
};


class Solution {
public:

    // ! APPROACH : Column Traversal + Reverse
    // ! T.C. : O(N*N)
    // ! S.C. : O(N*N)

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> result;

        for(int col = 0; col < n; col++)
        {
            vector<int> arr;

            for(int row = 0; row < n; row++)
            {
                arr.push_back(matrix[row][col]);
            }

            reverse(arr.begin(), arr.end());

            result.push_back(arr);
        }

        matrix = result;
    }
};




class Solution {
public:

    // ! APPROACH : Reverse Row Traversal
    // ! T.C. : O(N*N)
    // ! S.C. : O(N*N)

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> result;

        for(int col = 0; col < n; col++)
        {
            vector<int> arr;

            for(int row = n - 1; row >= 0; row--)
            {
                arr.push_back(matrix[row][col]);
            }

            result.push_back(arr);
        }

        matrix = result;
    }
};