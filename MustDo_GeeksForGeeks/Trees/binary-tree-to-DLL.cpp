/*
	Convert Binary Tree to Doubly Linked List
*/
/*
	Approach 1 - DFS + Store Path O(n) space
		Get Inorder Traversal Path with DFS
		Convert the path nodes to DLL

	Approach 2 - Segment Tree Like Build O(1) space
		Have Left subtree and Right subtree end points and combine them at every node
*/


/* Structure for tree and linked list

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

// Approach 1
vector<Node *> path;
void dfs(Node *root)
{
    if(root == NULL)
        return;
    dfs(root->left);
    path.push_back(root);
    dfs(root->right);
}
Node *bToDLL(Node *root)
{
    path.clear();
    dfs(root);
    int n = path.size();
    for(int i = 1; i < n; i++)
    {
        path[i - 1]->right = path[i];
        path[i]->left = path[i - 1];
    }
    path[0]->left = NULL;
    path[n - 1]->right = NULL;
    return path[0];
}

// Approach 2
pair<Node *, Node *> dfs(Node *root)
{
    if(root == NULL)
        return {NULL, NULL};
    if(root->left && root->right)
    {
        // Get Left Subtree and Right Subtree
        pair<Node *, Node *> left_subtree = dfs(root->left);
        pair<Node *, Node *> right_subtree = dfs(root->right);

        // Create new Node
        Node *ptr = newNode(root->data);

        // Join Node with Left subtree
        ptr->left = left_subtree.second;
        left_subtree.second->right = ptr;

        // Join Node with Right subtree
        ptr->right = right_subtree.first;
        right_subtree.first->left = ptr;

        return {left_subtree.first, right_subtree.second};
    }
    else if(root->right)
    {
        // Get Right Subtree
        pair<Node *, Node *> right_subtree = dfs(root->right);

        // Create new Node
        Node *ptr = newNode(root->data);

        // Join Node with Right subtree
        ptr->right = right_subtree.first;
        right_subtree.first->left = ptr;

        return {ptr, right_subtree.second};
    }
    else if(root->left)
    {
        // Get Right Subtree
        pair<Node *, Node *> left_subtree = dfs(root->left);

        // Create new Node
        Node *ptr = newNode(root->data);

        // Join Node with Left subtree
        ptr->left = left_subtree.second;
        left_subtree.second->right = ptr;

        return {left_subtree.first, ptr};
    }
    else
    {
        // Create new Node
        Node *ptr = newNode(root->data);

        // Since there are no subtrees return itself
        return {ptr, ptr};
    }
}
Node *bToDLL(Node *root)
{
    return dfs(root).first;
}