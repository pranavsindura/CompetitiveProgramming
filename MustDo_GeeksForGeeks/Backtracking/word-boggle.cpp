/*
	Given a dictionary, a method to do lookup in dictionary and a M x N board
	where every cell has one character.
	Find all possible words that can be formed by a sequence of adjacent characters.
	Note that we can move to any of 8 adjacent characters,
	but a word should not have multiple instances of same cell.
*/

/*
	Approach 1 - DFS like backtracking
	From each alphabet in the array try to form different words by going in 8 directions
	Find all different words
	Match them against the dictionary

	OPTIMIZATIONS

	1. Notice that board can have dimension 7x7 that means there might lot of paths with length 49
		Whereas the dictionary words are not that long
		We can keep track of the longest word in the dictionary
		If our path length exceeds this length we can stop checking its children

	2. We need only distinct words to whenever first occurance is found, simply remove it from the
		dictionary to avoid duplicates

	Approach 2 - Trie
		Have not learnt it yet
*/
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int n, m;
char arr[8][8];
bool vis[8][8];
unordered_map<string, bool> dict;
int mx_len;
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]);
}

void rec(int x, int y, string &word, vector<string> &ans)
{
    // OPTIMIZATION 1
    if(ln(word) > mx_len)
        return;
    vis[x][y] = true;
    // OPTIMIZATION 2
    if(dict.count(word))
        ans.pb(word), dict.erase(word);
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx, ny))
        {
            word.pb(arr[nx][ny]);
            rec(nx, ny, word, ans);
            word.pop_back();
        }

    }
    vis[x][y] = false;
}

void cp()
{
    int dict_len;
    cin >> dict_len;
    dict.clear();
    mx_len = 0;
    for(int i = 0; i < dict_len; i++)
    {
        string x;
        cin >> x;
        dict[x] = true;
        mx_len = max(mx_len, ln(x));
    }
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<string> ans;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            string word;
            word.pb(arr[i][j]);
            rec(i, j, word, ans);
        }
    }
    sort(begin(ans), end(ans));
    if(!ans.empty())
    {
        for(string &x : ans)
            cout << x << " ";
    }
    else
        cout << -1;
    cout << endl;
}