class Solution
{
public:
    int median(vector<vector<int>> &mat)
    {

        vector<int> vec;

        int n = mat.size();
        int m = mat[0].size();

        // flatten the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vec.push_back(mat[i][j]);
            }
        }

        // sort the flattened array
        sort(vec.begin(), vec.end());

        // median is middle element (total elements = n*m)
        int total = n * m;
        return vec[total / 2];
    }
};



class Solution {
public:
    int median(vector<vector<int>>& mat) {

        int rows = mat.size();                    // number of rows
        int cols = mat[0].size();                 // number of columns

        // ----------------------------------------------
        // STEP 1: Find global minimum & maximum values
        // ----------------------------------------------
        int lowVal  = mat[0][0];                  // smallest element seen so far
        int highVal = mat[0][cols - 1];           // largest element seen so far

        for (int r = 1; r < rows; r++) {
            lowVal  = min(lowVal,  mat[r][0]);         // first element of each row
            highVal = max(highVal, mat[r][cols - 1]);  // last element of each row
        }

        // median position (1-indexed)
        int neededCount = (rows * cols + 1) / 2;

        // ---------------------------------------------------------
        // STEP 2: Binary Search on value range (not index range!)
        // ---------------------------------------------------------
        while (lowVal < highVal) {

            int midVal = lowVal + (highVal - lowVal) / 2;
            int countLessOrEqual = 0;             // count elements <= midVal

            // count elements <= midVal in each row using upper_bound
            for (int r = 0; r < rows; r++) {
                countLessOrEqual += upper_bound(mat[r].begin(), mat[r].end(), midVal)
                                   - mat[r].begin();
            }

            // If count is smaller than needed, median must be higher
            if (countLessOrEqual < neededCount) {
                lowVal = midVal + 1;
            }
            // Otherwise shrink the upper bound
            else {
                highVal = midVal;
            }
        }

        return lowVal;        // this is the median value
    }
};
