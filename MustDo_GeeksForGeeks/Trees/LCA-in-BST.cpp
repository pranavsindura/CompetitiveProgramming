/*
	Find LCA of two nodes n1, n2 in a BST rooted at ROOT
*/

/*
	Approach - If Both nodes lie on different sides then current node is LCA
		Can be used recursively
*/

/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root'
Node *LCA(Node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(n1 < root->data && n2 < root->data) // both lie on left side
        return LCA(root->left, n1, n2);
    else if(n1 > root->data && n2 > root->data) // both lie on right side
        return LCA(root->right, n1, n2);
    else // both lie on different sides, current node is LCA

        return root;
}
