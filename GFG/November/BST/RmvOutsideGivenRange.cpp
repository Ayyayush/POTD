/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> removedKeys;   // Removed keys store karne ke liye

    Node* removekeys(Node* root, int l, int r) {
        if(root == NULL) return NULL;                 // Base case

        // Recursively process left and right subtrees
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);

        // Agar node out of range hai → remove it
        if(root->data < l || root->data > r) {
            removedKeys.push_back(root->data);
            // Return non-null child ya NULL
            if(root->left) return root->left;
            else return root->right;
        }

        return root;                                  // Node in range → keep it
    }
};
