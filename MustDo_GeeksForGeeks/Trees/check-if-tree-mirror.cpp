/*
	Check if Tree is a Mirror of itself (Symmetric Tree)
*/
/*
	Approach - Recursion
*/

// return true/false denoting whether the tree is Symmetric or not

bool check(Node *r1, Node *r2)
{
    if(r1 && r2)
    {
        if(r1->data != r2->data)
            return false;
        else
            return check(r1->left, r2->right) && check(r1->right, r2->left);
    }
    else if(r1 == NULL && r2 == NULL)
        return true;
    else
        return false;
}

bool isSymmetric(struct Node *root)
{
    return check(root, root);
}