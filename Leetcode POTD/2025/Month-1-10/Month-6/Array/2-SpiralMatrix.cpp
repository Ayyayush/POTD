class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();                   // total number of rows
        int n = matrix[0].size();                // total number of columns

        vector<int> result;                      // final spiral order traversal store hoga yahan

        // Define the boundaries of the matrix
        int top = 0;                             // top row ka index
        int bottom = m - 1;                      // bottom row ka index
        int left = 0;                            // leftmost column ka index
        int right = n - 1;                       // rightmost column ka index

        int dir = 0;                             // direction indicator: 0 -> left to right, 1 -> top to bottom,
                                                 //                      2 -> right to left, 3 -> bottom to top

        while (top <= bottom && left <= right)  // jab tak boundaries valid hain, tab tak spiral traversal chalega
        {
            if (dir == 0)
            {
                // Direction 0: Traverse left to right along the top row
                for (int i = left; i <= right; i++)
                    result.push_back(matrix[top][i]);
                top++;                          // top row traverse ho gaya, ab uske neeche move karo
            }

            else if (dir == 1)
            {
                // Direction 1: Traverse top to bottom along the rightmost column
                for (int i = top; i <= bottom; i++)
                    result.push_back(matrix[i][right]);
                right--;                        // right column process ho gaya, ab ek column left move karo
            }

            else if (dir == 2)
            {
                // Direction 2: Traverse right to left along the bottom row
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;                       // bottom row traverse ho gaya, ab ek row upar move karo
            }

            else if (dir == 3)
            {
                // Direction 3: Traverse bottom to top along the leftmost column
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;                         // left column ho gaya, ab ek column right move karo
            }

            dir = (dir + 1) % 4;                // direction ko cycle karo: 0→1→2→3→0→...
        }

        return result;                          // final spiral order return karo
    }
};
