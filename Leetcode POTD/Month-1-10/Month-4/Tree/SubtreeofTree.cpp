#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node *buildtree(vector<int> &nodes)
{
    idx++;
    if (nodes[idx] == -1)
        return NULL;

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildtree(nodes);
    currNode->right = buildtree(nodes);
    return currNode;
}

void levelorder(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
        return;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << endl;
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftht = height(root->left);
    int rightht = height(root->right);
    return max(leftht, rightht) + 1;
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftd = height(root->left);
    int rightd = height(root->right);
    int currd = leftd + rightd + 1;
    return currd;
}



int main()
{
    vector<int> nodes{1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildtree(nodes); // Constructing the tree from given input
    // preOrder(root);
    cout << endl;

    cout << "height is " << height(root) << endl;

    cout << "Diameter is " << diameter(root) << endl;
    Node *root = buildtree(2);
    Node *root = buildtree(3);
    Node *root = buildtree(5);

    cout << issubtree(root, subroot) << endl;

    return 0;
}
