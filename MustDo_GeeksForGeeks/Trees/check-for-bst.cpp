/*
	Check if Tree is BST
	1. No duplicates
	2. Nodes on left must be strictly less than Current node
	2. Nodes on right must be strictly greater than Current node
*/

pair<int, bool> dfs(Node *root)
{
    int me = root->data;

    pair<int, bool> left = {me - 1, true};
    if(root->left)
        left = dfs(root->left);

    pair<int, bool> right = {me + 1, true};
    if(root->right)
        right = dfs(root->right);

    bool ok = (left.first < me && right.first > me && left.second && right.second);

    int max_val = me;
    if(root->left)
        max_val = max(max_val, left.first);
    if(root->right)
        max_val = max(max_val, right.first);
    
    return {max_val, ok};
}

bool isBST(Node *root)
{
    return dfs(root).second;
}