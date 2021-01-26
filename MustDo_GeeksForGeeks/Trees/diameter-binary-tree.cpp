/*
    Find Diameter of Binary Tree
    Max length path between 2 leaves
*/
/*
    Approach 1 - Recursion similar to max path sum
        Similar to max path sum, now root->data has been replaced with 1

    Approach 2 - Recursion but no more nuances hence shorter code
*/
// Approach 1
int max_len;
int dfs(Node *root, Node *parent)
{
    if(root == NULL)
        return 0;
    if(root->left && root->right)
    {
        int ls = dfs(root->left, root);
        int rs = dfs(root->right, root);
        max_len = max(max_len, ls + rs + 1);
        return max(ls, rs) + 1;
    }
    else if(root->left)
    {
        int ls = dfs(root->left, root);
        if(parent == NULL)
            max_len = max(max_len, ls + 1);
        return ls + 1;
    }
    else if(root->right)
    {
        int rs = dfs(root->right, root);
        if(parent == NULL)
            max_len = max(max_len, rs + 1);
        return rs + 1;
    }
    else
    {
        return 1;
    }
}
int diameter(Node *node)
{
    // Your code here
    max_len = 1;
    dfs(node, NULL);
    return max_len;
}

// Approach 2
int dfs(Node *root, int &max_len)
{
    if(root == NULL)
        return 0;

    int left_height = dfs(root->left, max_len);
    int right_height = dfs(root->right, max_len);

    max_len = max(left_height + right_height + 1, max_len);

    return max(left_height, right_height) + 1;
}
int diameter(Node *node)
{
    // Your code here
    int max_len = 0;
    max_len = max(max_len, dfs(node, max_len));
    return max_len;
}