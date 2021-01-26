/*
	Check is Two trees are identical
*/
/*
	Approach - Recursion
	
*/

/* A binary tree node


struct Node
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

/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    if(r1 && r2)
    {
        if(r1->data != r2->data)
            return false;
        else
            return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
    else if(r1 == NULL && r2 == NULL)
        return true;
    else
        return false;
}