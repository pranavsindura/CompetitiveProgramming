/*
	Given two sorted arrays A and B of size M and N respectively and an element k.
	The task is to find the element that would be at the k’th position of the final sorted array.
*/

/*
	Approach 1 - Merge and Find
	Approach 2 - Merge withour extra space as we only need to keep track of the kth element
*/

// Approach 2
void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;

    int i = 0, j = 0;
    int ans = 0;

    while(i < n && j < m)
    {
        int placed = 0;
        if(a[i] <= b[j])
            placed = a[i], i++;
        else
            placed = b[j], j++;
        int total = i + j;
        if(total == k)
            ans = placed;
    }

    while(i < n)
    {
        int placed = a[i];
        i++;
        int total = i + j;
        if(total == k)
            ans = placed;
    }

    while(j < m)
    {
        int placed = b[j];
        j++;
        int total = i + j;
        if(total == k)
            ans = placed;
    }
    
    cout << ans << endl;
}