/*
	Check if Tree is Balanced
	Difference of Height of left subtree and Right Subtree should be <= 1
*/

/*
	Approach 1 -  Recursion
		Let us store both height and a flag denoting if my state is balanced or not
		Find state for left child
		Find state for right child
		Check difference of heights and set flags accordingly

*/

pair<int, bool> dfs(Node *root)
{
    if(root == NULL)
        return {0, true};

    pair<int, bool> left = dfs(root->left);
    pair<int, bool> right = dfs(root->right);

    bool ok = true;
    if(abs(left.first - right.first) > 1)
        ok = false;

    return {1 + max(left.first, right.first), ok && left.second &&right.second};
}

bool isBalanced(Node *root)
{
    return dfs(root).second;
}