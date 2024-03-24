/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node* createTree(vector<int>&arr){
if(arr.empty())
{
    return NULL;
}
Node* root=new Node(arr[0]);
queue<Node*>q;
q.push(root);
int i=1;
while(!q.empty() && i<arr.size())
{
    Node* current=q.front();
    q.pop();
    int leftval=arr[i++];
    if(leftval!=-1)
    {
        current->left=new Node(leftval);
        q.push(current->left);
    }
    if(i<arr.size())
    {
        int rightval=arr[i++];
        if(rightval!=-1)
        {
            current->right=new Node(rightval);
            q.push(current->right);
        }
    }
}
return root;
}
