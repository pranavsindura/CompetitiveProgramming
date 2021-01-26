/*
	Given 2 sorted arrays A and B of size N each.
	Print sum of middle elements of the array obtained after merging the given arrays.
*/

/*
	Approach 1 - Merge and Find
	Approach 2 - Merge without extra space because we only need position n-1 and n
*/
// Approach 1
void cp()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;
    vector<int> merge;
    int i = 0, j = 0;
    while(i < n && j < n)
    {
        if(a[i] <= b[j])
            merge.pb(a[i]), i++;
        else
            merge.pb(b[j]), j++;
    }
    while(i < n)
        merge.pb(a[i]), i++;
    while(j < n)
        merge.pb(b[j]), j++;
    cout << merge[n - 1] + merge[n] << endl;
}
