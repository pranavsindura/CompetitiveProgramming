/*
	Find Kth largest element in stream
*/

/*
	Approach 1 - Use Min - Priority Queue
		Push element to queue
		If size exceeds capacity pop
		print top element
*/

void cp()
{
    int k, n;
    cin >> k >> n;
    int ele = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int kth = -1;
        pq.push(x);
        ele++;
        if(ele > k)
            pq.pop(), ele--;
        if(ele == k)
            kth = pq.top();
        cout << kth << " ";
    }
    cout << endl;
}
