/*
	Find Maximum path sum from one leaf to another
*/
/*
	Approach 1 - Recursion
		Let recursion return the value of the max path starting from root to some leaf

		Need to handle two, one or zero child case separately
		In case of two child max path can be left subtree max path + node + right subtree max path
		In case of one child check for max only when parent is NULL i.e then it become leaf as well
		In case of zero child dont check
*/

/*Complete the function below
Node is as follows
struct Node{
    int data;
    Node *left, *right;
};
*/
int max_sum;
int dfs(Node *root, Node *parent)
{
    if(root == NULL)
        return 0;
    if(root->left && root->right)
    {
        int ls = dfs(root->left, root);
        int rs = dfs(root->right, root);
        max_sum = max(max_sum, ls + rs + root->data);
        return max(ls, rs) + root->data;
    }
    else if(root->left)
    {
        int ls = dfs(root->left, root);
        if(parent == NULL)
            max_sum = max(max_sum, ls + root->data);
        return ls + root->data;
    }
    else if(root->right)
    {
        int rs = dfs(root->right, root);
        if(parent == NULL)
            max_sum = max(max_sum, rs + root->data);
        return rs + root->data;
    }
    else
    {
        return root->data;
    }
}
int maxPathSum(Node *root)
{
    max_sum = INT_MIN;
    dfs(root, NULL);
    return max_sum;
}