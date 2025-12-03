#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode structure
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class FindElements {
public:
    unordered_set<int> st; // Set to store valid values of recovered tree

    // Recursive DFS function to restore tree
    void dfs(TreeNode* root, int x) {
        if (!root) return; // Base case: If root is NULL, return

        root->val = x; // Assign correct value to current node
        st.insert(x); // Insert value in set

        dfs(root->left, 2 * x + 1); // Restore left child
        dfs(root->right, 2 * x + 2); // Restore right child
    }

    // Constructor to initialize tree recovery using DFS
    FindElements(TreeNode* root) {
        st.clear(); // Clear previous values
        dfs(root, 0); // Start DFS with root value as 0
    }

    // Function to check if a value exists in recovered tree
    bool find(int target) {
        return st.count(target); // Return true if target exists in set
    }
};

class FindElementsBFS {
public:
    unordered_set<int> st; // Set to store valid values of recovered tree

    // BFS function to restore tree
    void bfs(TreeNode* root, int x) {
        queue<TreeNode*> que;
        root->val = x; // Assign correct value to root
        que.push(root); // Push root into queue

        while (!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();

            st.insert(temp->val); // Insert value into set

            if (temp->left) {
                temp->left->val = 2 * temp->val + 1; // Restore left child
                que.push(temp->left);
            }
            if (temp->right) {
                temp->right->val = 2 * temp->val + 2; // Restore right child
                que.push(temp->right);
            }
        }
    }

    // Constructor to initialize tree recovery using BFS
    FindElementsBFS(TreeNode* root) {
        st.clear(); // Clear previous values
        bfs(root, 0); // Start BFS with root value as 0
    }

    // Function to check if a value exists in recovered tree
    bool find(int target) {
        return st.count(target); // Return true if target exists in set
    }
};

int main() {
    return 0;
}
