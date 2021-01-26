/*
	MISSING PLATFORMS
	Given list of arrival and departure times of n buses/trains
	count minimum platforms needed for safe travel
*/

/*	Approach 1 - Brute force O(n^2)
	for each train see how many is overlaps with, maximum overlaps + 1 is the answer

	Approach 2 - Two pointer O(n)
	Sort list of arrival and departure times
	have two pointers one for arrival and one for departure
	if ith arrival occurs before jth departure can occur
		one more platform is needed, add it go to next arrival
	else
		one less platform is now needed, remove it go to next departure
	Overall maximum platforms needed is the answer

*/

void cp()
{
    int n;
    cin>>n;
    vector<int> a(n), d(n);
    for(int &x:a)cin>>x;
    for(int &x:d)cin>>x;
    sort(all(a));
    sort(all(d));
    int plat = 1, ans = 1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(a[i] <= d[j])
        {
            // if ith train arrives before jth train can depart, more platform needed
            plat++;
            i++;
        }
        else
        {
            //jth train can safely depart
            j++;
            plat--;
        }
        ans = max(ans, plat);
    }
    cout<<ans<<endl;
}