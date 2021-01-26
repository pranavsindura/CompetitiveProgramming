/*
	Activity Selection

	Given List of Start and End times of an Activity find the maximum number of activities that can be performed
	Start and End times may overlap, considered OK

*/

/*
	Approach -
		Sort by End timing and greedily perform activity

		If can perform ith ativity such that the Last activity does not overlap Do it, Make it last activity
		Count how many i can perform

		Works because sorted by End times, Previous activity can only start and end before my current activity ends
*/
bool overlap(pi a, pi b)
{
    return !(max(a.ff, b.ff) >= min(a.ss, b.ss));
}
void cp()
{
    int n;
    cin >> n;
    vector<pi> range(n);
    for(int i = 0; i < n; i++)
        cin >> range[i].ff;
    for(int i = 0; i < n; i++)
        cin >> range[i].ss;
    sort(all(range), [](pi a, pi b)
    {
        return a.ss < b.ss;
    });
    int last = 0;
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(overlap(range[i], range[last]))
        {
            //cannot perform task i
        }
        else
        {
            //can perform task i
            cnt++;
            last = i;
        }
    }
    cout << cnt << endl;
}