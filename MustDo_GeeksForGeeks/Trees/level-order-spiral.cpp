/*
	Level Order Traversal in Spiral Form
*/

/*
	Approach - 
		Simple BFS while storing nodes at each level
		Reversing printing when required
*/
#define sz(x) ((int)x.size())
void printSpiral(Node *root)
{
    map<int, vector<int>> nodes_at_level;
    queue<pair<Node *, int>> q;
    if(root)
        q.push({root, 0});
    while(!q.empty())
    {
        pair<Node *, int> u_node = q.front();
        q.pop();
        Node *u = u_node.first;
        int lvl = u_node.second;

        nodes_at_level[lvl].push_back(u->data);
        if(u->left)
            q.push({u->left, lvl + 1});
        if(u->right)
            q.push({u->right, lvl + 1});
    }
    bool flip = true;
    for(auto nodes_arr : nodes_at_level)
    {
        if(flip)
        {
            for(int i = sz(nodes_arr.second) - 1; i >= 0; i--)
                cout << nodes_arr.second[i] << " ";
        }
        else
        {
            for(int i = 0; i < sz(nodes_arr.second); i++)
                cout << nodes_arr.second[i] << " ";
        }
        flip = !flip;
    }
}