/*
	Maximize toys
	Given cost of each toy and budget K
	Maxmize the number of toys bought
*/
/*
	Approach - O(nlogn)
		Sort and pick the smallest cost toys till their sum is <= K

		Can be derived from a knapsack problem but the benefit is the same i.e. 1
		So greedy works by minimizing cost
*/

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(all(arr));
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum <= k)
            cnt++;
        else
            break;
    }
    cout << cnt << endl;
}
