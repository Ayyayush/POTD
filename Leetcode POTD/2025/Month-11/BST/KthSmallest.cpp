#include <bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    vector<int> arr; // inorder elements ko store karne ke liye

    // ✅ Inorder traversal function
    void in(Node *root)
    {
        if (!root)
            return; // base case: agar null mila toh return

        in(root->left);            // left subtree traverse karo
        arr.push_back(root->data); // root ka data store karo
        in(root->right);           // right subtree traverse karo
    }

    // ✅ Function to find kth smallest element in BST
    int kthSmallest(Node *root, int k)
    {
        arr.clear(); // purana data clear kar do
        in(root);    // inorder traversal se sorted order milta hai

        if (k > 0 && k <= arr.size()) // boundary check
            return arr[k - 1];        // kth smallest element return karo
        else
            return -1; // agar k invalid hua toh -1 return
    }
};
