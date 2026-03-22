/**
 * leetcode 1886
 * determine wether marix can be obtained by rotation
 * 
 * problem description 
 * 
 * 
 * Thought process
 * 
 * how do we roate 90 degree 
 * sabse simple taria h extra space leke 
 * 1t row ko lst col mein 
 * 2nd row ko 2d last col mein and so on 
 * eg :
 * 
 * 
 * 
 * better approach without etxtra space 
 * ! important rule to remeber 
 * transpose nikalo 
 * and har row ko reverse kar do 
 * eg dekhte h 
 * 
 * and afar trnaspose kakr ecol ko reverse kr diya 
 * toh antiloxk wise roate ho jayega 
 * 
 */

 class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        int n = mat.size();
        int count = 0;

        while (mat != target)
        {
            vector<vector<int>> arr(n, vector<int>(n));

            for (int i = 0; i < n; i++)
            {
                int row = 0;
                int col = n - 1 - i;

                for (int j = 0; j < n; j++)
                {
                    arr[row++][col] = mat[i][j];
                }
            }

            mat = arr;
            count++;

            if (count >= 4)
                return false;
        }
        return true;
    }
};


/******************************************** C++ ********************************************/
//Approach (Rotate and check till 4 rotations)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int n;

    void rotate(vector<vector<int>>& mat) {
        //Transpose

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        //Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        for(int c = 1; c <= 4; c++) {
            
            bool equal = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if(!equal)
                    break;
            }

            if(equal)
                return true;
                
            rotate(mat);
        }

        return false;
    }
};

