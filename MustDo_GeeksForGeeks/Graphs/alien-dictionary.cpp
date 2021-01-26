/*
	Alien Dictionary

	Given a List of strings, sorted in the lexicographically in alien language
	Find the lexical order of the alphabets
	Given that only first K letters of human alphabet are used
*/
/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
/*
	Approach 1 -
		Break the Strings into groups of those which share same FIRST letter
		Now out of all the distinct FIRST letters you have a part of the lexical order

		Lets say first letters were

		b,d,c,a
		this means that in lexical order
		b comes before d
		d comes before c
		c comes before a

		So form a graph and find the Topological Sorting Order!

		b->d->c->a

		Now The string you grouped together, remove their first character and recursively Perform this Graph forming
		till strings are not empty or only 1 group is present


		After you have the graph simple find the Topological order



		Approach 2 -

			Notice that we end up comparing the strings which are adjacent
			So instead of grouping and heavy recursion we can just compare adjacent strings
			till we find a character that is different for some position i in the two string

			Form graph as above and TopSort
*/

// APPROACH 2

void solve(vector<string> &arr, vector<vector<int>> &adj)
{
    for(int i = 0; i < sz(arr) - 1; i++)
    {
        string a = arr[i], b = arr[i + 1];
        for(int j = 0; j < min(ln(a), ln(b)); j++)
        {
            if(a[j] != b[j])
            {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }
}

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj, string &top_sort)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(!vis[v])
            dfs(v, vis, adj, top_sort);
    }
    top_sort += char(97 + u);
}

string findOrder(string dict[], int N, int K)
{
    vector<vector<int>> adj(K);
    vector<string> arr(dict, dict + N);
    solve(arr, adj);
    string top_sort;
    vector<bool> vis(K, false);
    for(int i = 0; i < K; i++)
    {
        if(!vis[i])
            dfs(i, vis, adj, top_sort);
    }
    reverse(all(top_sort));
    return top_sort;
}


// Approach 1
// Strings are reversed for ease of removal of first character

void solve(vector<string> &arr, vector<vector<int>> &adj)
{
    // Groups <= 1
    if((int)arr.size() <= 1)
        return;
    vector<char> last;
    for(string &x : arr)
    {
        // Getting Last character
        if(!x.empty())
            last.push_back(x.back());
    }
    char dis = last[0];
    // Finding Distinct Characters and Forming Graph
    for(int i = 1; i < (int)last.size(); i++)
    {
        if(last[i] == dis)
            continue;
        else
            adj[dis - 'a'].push_back(last[i] - 'a'), dis = last[i];
    }
    // Making new Graphs
    vector<vector<string>> group(26);
    for(string &x : arr)
    {
        if(!x.empty())
            group[x.back() - 'a'].push_back(x);
    }
    // Remove last character
    for(vector<string> &x : group)
    {
        for(string &xx : x)
            xx.pop_back();
    }
    //Recursively solving for remaining groups
    for(vector<string> &x : group)
        solve(x, adj);
}

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj, string &top_sort)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(!vis[v])
            dfs(v, vis, adj, top_sort);
    }
    top_sort += char(97 + u);
}

string findOrder(string dict[], int N, int K)
{
    vector<vector<int>> adj(K);
    vector<string> arr(dict, dict + N);

    // Strings are reversed for ease of removal of first character
    for(string &x : arr)
        reverse(all(x));

    solve(arr, adj);
    string top_sort;

    vector<bool> vis(K, false);
    for(int i = 0; i < K; i++)
    {
        if(!vis[i])
            dfs(i, vis, adj, top_sort);
    }
    reverse(all(top_sort));
    return top_sort;
}
