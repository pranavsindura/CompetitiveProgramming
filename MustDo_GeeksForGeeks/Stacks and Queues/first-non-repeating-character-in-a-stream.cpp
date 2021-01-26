/*
	Find First Non repeating character in a Stream
*/
/*
	Approach 1 - List Based, Simlar to LRU O(n)
		Every time i see a new character move it to the front of the list, store its position
		Every time a character repeats delete it from list
		The First Character that is not repeating is at the end of the list

	Approach 2 - Queue Based
		Push char into queue
		While frequency of first character is > 1 start popping
		You will either find a character with frequency == 1 or queue will be empty
*/

// Approach 1
void cp()
{
    int n;
    cin >> n;
    vector<char> arr(n);
    for(char &x : arr)
        cin >> x;
    list<char> candidate;
    vector<list<char>::iterator> pos(26);
    vector<bool> del(26, false);
    int cnt[26] = {0};
    for(int i = 0; i < n; i++)
    {
        cnt[arr[i] - 'a']++;
        if(cnt[arr[i] - 'a'] == 1)
        {
            candidate.push_front(arr[i]);
            pos[arr[i] - 'a'] = candidate.begin();
        }
        else
        {
            if(!del[arr[i] - 'a'])
                candidate.erase(pos[arr[i] - 'a']), del[arr[i] - 'a'] = true;
        }
        if(sz(candidate))
            cout << candidate.back() << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
}

// Approach 2
void cp()
{
    int n;
    cin >> n;
    vector<char> arr(n);
    for(char &x : arr)
        cin >> x;
    queue<char> q;
    int cnt[26] = {0};
    for(int i = 0; i < n; i++)
    {
        cnt[arr[i] - 'a']++;
        q.push(arr[i]);
        while(!q.empty())
        {
            char u = q.front();
            if(cnt[u - 'a'] > 1)
                q.pop();
            else
                break;
        }
        if(sz(q))
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
}