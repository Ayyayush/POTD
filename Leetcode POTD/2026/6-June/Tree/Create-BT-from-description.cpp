/**
 * =====================================================================
 * ! LEETCODE 2196 : CREATE BINARY TREE FROM DESCRIPTIONS
 * =====================================================================
 *
 * Given descriptions:
 *
 * descriptions[i] = [parent, child, isLeft]
 *
 * parent  -> parent node value
 * child   -> child node value
 * isLeft  -> 1 => left child
 *            0 => right child
 *
 * We have to construct and return the ROOT of the binary tree.
 *
 * ---------------------------------------------------------------------
 * ! IMPORTANT OBSERVATION
 * ---------------------------------------------------------------------
 *
 * Hume input array dekh kar directly root nahi pata chalega.
 *
 * Lekin root ki ek special property hoti hai:
 *
 * 👉 Root kabhi bhi kisi ka child nahi hota.
 *
 * Isliye:
 *
 * Parent values collect karo.
 * Child values collect karo.
 *
 * Jo node parent hai lekin kabhi child nahi bani,
 * wahi final root hogi.
 *
 * ---------------------------------------------------------------------
 * ! EXAMPLE
 * ---------------------------------------------------------------------
 *
 * descriptions =
 *
 * [
 *   [20,15,1],
 *   [20,17,0],
 *   [50,20,1],
 *   [50,80,0],
 *   [80,19,1]
 * ]
 *
 *
 * --------------------------------------------------
 * Step 1 : [20,15,1]
 * --------------------------------------------------
 *
 * Check karo 20 bana hai kya?
 * Nahi.
 *
 * Create:
 *
 *      20
 *
 * Check karo 15 bana hai kya?
 * Nahi.
 *
 * Create:
 *
 *      20
 *     /
 *   15
 *
 * isLeft = 1
 *
 * So:
 *
 * 20->left = 15
 *
 * Aur note kar lo:
 *
 * 15 child hai
 * => 15 kabhi root nahi ho sakta
 *
 *
 * --------------------------------------------------
 * Step 2 : [20,17,0]
 * --------------------------------------------------
 *
 * 20 already bana hua hai.
 *
 * 17 nahi bana.
 *
 * Create:
 *
 *      20
 *     /  \
 *   15   17
 *
 * isLeft = 0
 *
 * So:
 *
 * 20->right = 17
 *
 * 17 child hai
 * => root nahi ho sakta
 *
 *
 * --------------------------------------------------
 * Step 3 : [50,20,1]
 * --------------------------------------------------
 *
 * 50 nahi bana.
 *
 * Create:
 *
 *        50
 *       /
 *     20
 *    /  \
 *  15   17
 *
 * 20 already exist karta hai.
 *
 * So:
 *
 * 50->left = 20
 *
 * 20 child hai
 * => root nahi ho sakta
 *
 *
 * --------------------------------------------------
 * Step 4 : [50,80,0]
 * --------------------------------------------------
 *
 * 80 create karo.
 *
 *         50
 *       /    \
 *     20      80
 *    /  \
 *  15   17
 *
 * 80 child hai.
 *
 *
 * --------------------------------------------------
 * Step 5 : [80,19,1]
 * --------------------------------------------------
 *
 * 19 create karo.
 *
 *         50
 *       /    \
 *     20      80
 *    /  \    /
 *  15   17 19
 *
 * 19 child hai.
 *
 *
 * ---------------------------------------------------------------------
 * ! ROOT FINDING
 * ---------------------------------------------------------------------
 *
 * Child Set =
 *
 * {15,17,20,80,19}
 *
 * Parents =
 *
 * {20,50,80}
 *
 * Check:
 *
 * 20 -> child bhi hai ❌
 * 80 -> child bhi hai ❌
 * 50 -> child nahi hai ✅
 *
 * Therefore:
 *
 * Root = 50
 *
 *
 * ---------------------------------------------------------------------
 * ! DATA STRUCTURES USED
 * ---------------------------------------------------------------------
 *
 * unordered_map<int, TreeNode*>
 *
 * Stores:
 *
 * value -> node address
 *
 * Example:
 *
 * mp[20] -> address of node 20
 * mp[15] -> address of node 15
 *
 *
 * unordered_set<int> childSet
 *
 * Stores all nodes that appeared as child.
 *
 * Child can never be root.
 *
 *
 * ---------------------------------------------------------------------
 * ! ALGORITHM
 * ---------------------------------------------------------------------
 *
 * Pass 1:
 *
 * For every description:
 *
 * 1. Create parent node if not present.
 * 2. Create child node if not present.
 * 3. Connect parent and child.
 * 4. Insert child into childSet.
 *
 *
 * Pass 2:
 *
 * Traverse descriptions again.
 *
 * First parent which is NOT present
 * inside childSet is the root.
 *
 *
 * ---------------------------------------------------------------------
 * ! TIME COMPLEXITY
 * ---------------------------------------------------------------------
 *
 * First pass  : O(n)
 * Second pass : O(n)
 *
 * Total:
 *
 * T.C = O(n)
 *
 *
 * ---------------------------------------------------------------------
 * ! SPACE COMPLEXITY
 * ---------------------------------------------------------------------
 *
 * Map      -> O(n)
 * ChildSet -> O(n)
 *
 * S.C = O(n)
 *
 */


 class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet;

        for(vector<int>& vec : descriptions)
        {
            int parent = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];

            // Create parent node if not present
            if(mp.find(parent) == mp.end())
            {
                mp[parent] = new TreeNode(parent);
            }

            // Create child node if not present
            if(mp.find(child) == mp.end())
            {
                mp[child] = new TreeNode(child);
            }

            // Connect parent with child
            if(isLeft == 1)
            {
                mp[parent]->left = mp[child];
            }
            else
            {
                mp[parent]->right = mp[child];
            }

            // Child can never be root
            childSet.insert(child);
        }

        // Find node which never appeared as child
        for(vector<int>& vec : descriptions)
        {
            int parent = vec[0];

            if(childSet.find(parent) == childSet.end())
            {
                return mp[parent];
            }
        }

        return nullptr;
    }
};