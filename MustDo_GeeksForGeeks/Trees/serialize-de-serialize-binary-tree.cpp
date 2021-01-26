/*
	Serialize and De Serialize a Binary Tree
*/

/*
	Store Preorder Traversal and Resconstruct from that
	Store -1 for positions that are NULL
*/
void serialize(Node *root, vector<int> &A)
{
    if(root == NULL)
    {
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

/*this function deserializes
 the serialized vector A*/

Node *build(vector<int> &arr, int &v)
{
    if(arr[v] == -1)
    {
        return NULL;
    }
    else
    {
        Node *root = new Node(arr[v]);
        v++;
        root->left = build(arr, v);
        v++;
        root->right = build(arr, v);
        return root;
    }
}

Node *deSerialize(vector<int> &A)
{
    int pos = 0;
    return build(A, pos);
}