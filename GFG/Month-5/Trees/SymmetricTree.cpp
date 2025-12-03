/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/


void preorder(Node* root,vector<int>&pre)
{
    if(root==NULL)
    return;
    
    pre.push_back(root->data);
    preorder(root->left,pre);
    preorder(root->right,pre);
    
}


void postorder(Node* root,vector<int>&post)
{
    if(root==NULL)
    return;
    
        post.push_back(root->data);
       postorder(root->right,post);
    postorder(root->left,post);
 

}
class Solution {
  public:
    bool isSymmetric(Node* root) {
        vector<int>pre,post;
        
        preorder(root->left,pre);
        postorder(root->right,post);
        
        return pre==post;
        // Code here
        
    }
};