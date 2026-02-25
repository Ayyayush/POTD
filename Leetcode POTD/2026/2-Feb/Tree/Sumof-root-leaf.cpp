#include <bits/stdc++.h>
using namespace std;

/**
 * ! amazon
 * 
 * Sum of root to leaf
 * 
 * jab bhi binary tree ka problem ata h recursion is the best way to write it up
 */

/**************************************************************** C++ *************************************************************/

/*
    Definition for a binary tree node.
*/
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;                 // node value assign
        left = NULL;             // left child initialize
        right = NULL;            // right child initialize
    }
};

void brute()
{
    // ❌ No brute force possible for this problem
    // Tree traversal itself visits all nodes
}

void better()
{
    // ❌ No better approach exists
    // Recursion is already optimal
}

void optimal()
{
    /**
     * Approach : Recursion (DFS)
     * T.C : O(n)                       // every node is visited once
     * S.C : O(1) Auxiliary
     *       O(n) System recursion stack (worst case – skew tree)
     */

    // ---------- HARD CODED TREE ----------
    /*
                1
               / \
              0   1
             / \   \
            0   1   1
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    // ---------- RECURSIVE FUNCTION ----------
    function<int(TreeNode*, int)> solve = [&](TreeNode* node, int val)
    {
        if(node == NULL)
            return 0;                             // base case

        val = (2 * val) + node->val;              // binary to decimal conversion

        if(node->left == NULL && node->right == NULL)
            return val;                           // leaf node reached

        return solve(node->left, val)             // left subtree sum
             + solve(node->right, val);            // right subtree sum
    };

    int ans = solve(root, 0);                     // initial value = 0

    cout << "Sum of Root to Leaf = " << ans << endl;
}

int main()
{
    optimal();                                    // calling optimal solution
    return 0;
}

/*
JS Optimal Approach (Recursion):
--------------------------------
function dfs(root, val) {
    if (!root) return 0;
    val = (val << 1) | root.val;
    if (!root.left && !root.right) return val;
    return dfs(root.left, val) + dfs(root.right, val);
}

Python Optimal Approach:
------------------------
def dfs(root, val):
    if not root:
        return 0
    val = (val << 1) | root.val
    if not root.left and not root.right:
        return val
    return dfs(root.left, val) + dfs(root.right, val)
*/