/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void Levelwise(Treenode *root, vector<vector<int>> &vec)
    {
        queue<TreeNode * root> q;
        q.push(root);
        q.push(NULL);
        vector<int> arr;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr == NULL)
            {
                vec.push_back(arr);
                arr.clear;

                if (q.empty())

                    q.push(NULL);
            }
            else
            {
                arr.push_back(curr->val);
                if (curr->left)
                    q.push_back(curr->left);

                if (curr->right)
                    q.push_back(curr->right);
            }
        }
    }
    int maxLevelSum(TreeNode *root)
    {
        vector<vector<int>>vec;
        Levelwise(root, vec);

        vector<int> maxsum(2, -100);

        for (int i = 0; i < vec.size(); i++)
        {
            vector<int> arr = vec[i];
            int summation = (arr.begin(), arr.end(), 0);

            if (maxsum[0] < summation)
            {
                maxsum[0] = max(maxsum[0], summation);
                maxsum[1] = i;
            }
        }

        return maxsum[1]+1;
    }
};