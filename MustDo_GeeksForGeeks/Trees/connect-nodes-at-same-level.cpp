/*
	Connect Nodes at Same level
	Form their own linked list, use pointer nextRight
*/
/*
	Approach - BFS, Store nodes, connect
*/

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
#define sz(x) ((int)x.size())
void connect(Node *root)
{
    map<int, vector<Node *>> nodes_at_level;
    queue<pair<Node *, int>> q;
    if(root)
        q.push({root, 0});
    while(!q.empty())
    {
        pair<Node *, int> u_node = q.front();
        q.pop();
        Node *u = u_node.first;
        int lvl = u_node.second;

        nodes_at_level[lvl].push_back(u);
        if(u->left)
            q.push({u->left, lvl + 1});
        if(u->right)
            q.push({u->right, lvl + 1});
    }
    for(auto node_arr_pair : nodes_at_level)
    {
        for(int i = 0; i < sz(node_arr_pair.second) - 1; i++)
            node_arr_pair.second[i]->nextRight = node_arr_pair.second[i + 1];
        node_arr_pair.second[sz(node_arr_pair.second) - 1]->nextRight = NULL;
    }
}