/*
    Print LeftView of a Binary Tree
*/

/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// A wrapper over leftViewUtil()
void leftView(Node *root)
{
   // Your code here
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    if(root->left)
        leftView(root->left);
    else
        leftView(root->right);
}