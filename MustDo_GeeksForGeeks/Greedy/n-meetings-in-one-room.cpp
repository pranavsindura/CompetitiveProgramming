/*
	N meetings in 1 Room
	Given list of start and end times of a meeting
	Count how many meetings can occur if none overlap and there is only 1 room
*/
/*
	Approach 1 - Find Subsets and check if they overlap O(2^n * n)

	Approach 2 - Sort by Ending Times and see if current meeting can occur given the last
		meeting that occured
		First meeting always occurs

		Greedy solution works because the meeting which ends first comes first
		O(nlogn)
*/
struct meeting
{
    int l, r, idx;
    meeting() {}
    meeting(int l, int r, int idx): l(l), r(r), idx(idx) {}
    bool operator<(const meeting &a)
    {
        return r < a.r;
    }
};
bool overlap(meeting a, meeting b)
{
    return !((a.l < b.l && a.r < b.l) || (b.l < a.l && b.r < a.l));
}

void cp()
{
    int n;
    cin >> n;
    vector<pi> times(n);
    for(pi &x : times)
        cin >> x.ff;
    for(pi &x : times)
        cin >> x.ss;
    vector<meeting> arr;
    for(int i = 0; i < n; i++)
    {
        arr.pb(meeting(times[i].ff, times[i].ss, i + 1));
    }
    sort(all(arr));
    vector<int> res;
    int last = 0;
    res.pb(arr[0].idx);
    for(int i = 1; i < n; i++)
    {
        if(!overlap(arr[last], arr[i]))
            res.pb(arr[i].idx), last = i;
    }
    for(int x : res)
        cout << x << " ";
    cout << endl;
}
