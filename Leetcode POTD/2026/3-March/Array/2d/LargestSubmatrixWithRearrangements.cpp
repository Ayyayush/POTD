/**
 * largest submatrix with rearrangements
 *  problem desscription
 *
 *
 * ! brute thought process
 *
 */

/*************************************************************** C++ ***************************************************************/
// Approach-1 (Using sorting)
// T.C : (m * nlogn)
// S.C : O(m*n)
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;

        for (int row = 0; row < m; row++)
        {

            for (int col = 0; col < n; col++)
            {

                if (matrix[row][col] == 1 && row > 0)
                {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }

            vector<int> currRow = matrix[row];
            sort(begin(currRow), end(currRow), greater<int>());
            for (int col = 0; col < n; col++)
            {
                int base = (col + 1); // iske peeche k columns me >= currRow[col] to hoga hi 1s
                int height = currRow[col];

                result = max(result, base * height);
            }
        }

        return result;
    }
};

// Approach-2 (Without modifying the given input)
// T.C : (m * nlogn)
// S.C : O(m*n)
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prevRow(n, 0);
        int result = 0;

        for (int row = 0; row < m; row++)
        {
            vector<int> currRow = matrix[row];

            for (int col = 0; col < n; col++)
            {

                if (currRow[col] == 1)
                {
                    currRow[col] += prevRow[col];
                }
            }

            vector<int> sortedRow = currRow;
            sort(begin(sortedRow), end(sortedRow), greater<int>());

            for (int col = 0; col < n; col++)
            {
                int base = (col + 1); // iske peeche k columns me >= currRow[col] to hoga hi 1s
                int height = sortedRow[col];

                result = max(result, base * height);
            }

            prevRow = currRow;
        }

        return result;
    }
};

/*
 * ! Approach: Histogram Build without Sorting (Greedy Expansion)
 * T.C = O(m * n)
 * S.C = O(m * n)
 */

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {

        int m = matrix.size();    // total rows
        int n = matrix[0].size(); // total columns

        vector<pair<int, int>> prevHeights; // previous row ke heights (height, column)
        int result = 0;                     // final max area

        // ! Har row ko treat karenge as base of histogram
        for (int row = 0; row < m; row++)
        {

            vector<pair<int, int>> heights; // current row ke heights
            vector<bool> seen(n, false);    // mark karega kaunse columns use ho chuke hain

            // ! Step 1: previous heights ko extend karo (agar current cell 1 hai)
            for (auto [height, col] : prevHeights)
            {

                if (matrix[row][col] == 1)
                {
                    heights.push_back({height + 1, col}); // height increase
                    seen[col] = true;                     // mark visited
                }
            }

            // ! Step 2: naye columns add karo jahan current row me 1 hai
            for (int col = 0; col < n; col++)
            {

                if (seen[col] == false && matrix[row][col] == 1)
                {
                    heights.push_back({1, col}); // new height = 1
                }
            }

            // ! Step 3: area calculate karo
            // NOTE: sorting nahi kar rahe → order maintained hai
            for (int i = 0; i < heights.size(); i++)
            {

                int base = (i + 1);            // width = number of columns taken
                int height = heights[i].first; // height of rectangle

                result = max(result, base * height); // area = base * height
            }

            // ! Step 4: current heights ko next iteration ke liye store karo
            prevHeights = heights;
        }

        return result; // final answer
    }
};