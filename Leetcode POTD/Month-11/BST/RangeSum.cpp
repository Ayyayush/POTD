//T.C : O(n)
//S.C : O(1) (Ignoging recursion stack space)
class Solution {
public:
   int nodeSum(Node* root, int l, int r) {
        if(!root)
            return 0;
        
        //Within Range
        if(root->data >= l && root->data <= r) {
            return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
        }
        
        //When outside the range (Less than l) - Go right
        if(root->data < l)
            return nodeSum(root->right, l, r);

        //When outside the range (Greater than r) - Go left
        return nodeSum(root->left, l, r);
    }
};

