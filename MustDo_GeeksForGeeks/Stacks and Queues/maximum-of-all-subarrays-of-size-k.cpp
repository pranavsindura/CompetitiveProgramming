/*
	Maximum in Subarray of length k
*/
/*
	Approach 1 - Brute Force O(n^3)
	Approach 2 - Using Sets/ Segment Tree O(nlogn)
	Approach 3 - Using Queues O(n)
		We don't need those elements which have greater elements on the right
*/

// Approach 3
void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    deque<int> dq;
    for(int i = 0; i < k; i++)
    {
        while(!(dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while(!(dq.empty()) && dq.front() <= i - k)
            dq.pop_front();
        while(!(dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
    cout << endl;
}