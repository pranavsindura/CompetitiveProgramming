/*
    Print Bottom View of a Tree
*/
/*
    Approach - Use BFS and store the offset of each node from the vertical plane fixed at ROOT
        Since the Lower nodes get priority using BFS makes sense
*/
void bottomView(Node *root)
{
    map<int, int> val;
    queue<pair<Node *, int>> q;
    if(root)
        q.push({root, 0});
    while(!q.empty())
    {
        pair<Node *, int> u_node = q.front();
        q.pop();
        Node *u = u_node.first;
        int pos = u_node.second;

        val[pos] = u->data;
        if(u->left)
            q.push({u->left, pos - 1});
        if(u->right)
            q.push({u->right, pos + 1});
    }
    for(auto x : val)
        cout << x.second << " ";
}