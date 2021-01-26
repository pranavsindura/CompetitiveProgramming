/*
	Find Height of Binary Tree
*/

/*
	Approach 1 - Use BFS O(n) space O(n) time
	Approach 2 - Use DFS O(h) stack space O(n) time
*/

// Approach 1
int height(Node *root)
{
    int max_depth = 0;
    queue<pair<Node *, int>> q;
    if(root)
        q.push({root, 1});
    while(!q.empty())
    {
        pair<Node *, int> u = q.front();
        q.pop();
        max_depth = max(max_depth, u.second);
        if(u.first->left)
            q.push({u.first->left, u.second + 1});
        if(u.first->right)
            q.push({u.first->right, u.second + 1});
    }
    return max_depth;
}
// Approach 2
int height(Node *root)
{
    if(root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}