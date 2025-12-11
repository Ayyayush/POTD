// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

*/
vector<int> displayList(Node *head) {
    vector<int>forward,backward;
    Node *temp =head;
    while(temp!=NULL)
    {
        forward.push_back(temp->data);
        temp=temp->next;
        
    }
    
    return forward ;
}