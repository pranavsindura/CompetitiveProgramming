/*
	Print Vertical Order Traversal of Tree
*/

/*
	Approach - Similar to Bottom View
		Here now you have to store the Nodes in an array and not replace them
		Still using BFS
*/
void verticalOrder(Node *root)
{
    map<int, vector<int>> trav;
    queue<pair<Node *, int>> q;
    if(root)
        q.push({root, 0});
    while(!q.empty())
    {
        pair<Node *, int> u_node = q.front();
        q.pop();
        Node *u = u_node.first;
        int pos = u_node.second;

        trav[pos].push_back(u->data);
        if(u->left)
            q.push({u->left, pos - 1});
        if(u->right)
            q.push({u->right, pos + 1});
    }
    for(auto pos_arr_pair : trav)
    {
        for(int num : pos_arr_pair.second)
            cout << num << " ";
    }
}
