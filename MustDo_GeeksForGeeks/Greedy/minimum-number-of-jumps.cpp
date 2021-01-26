/*
	Minimum number of jumps needed to reach end of array
	Arr[i] is the number of indexes you can jump from position i
*/
/*
	Approach 1 - Greedy
		For every index, we see if we can reach this index
		If we can,
			We can use this jump later on so we hold a max variable which maximizes the jump
			i.e. i + arr[i]
		If we can't,
			We can use the max jump, set my position to new position
			jumps++
			reset maxjump to current position i + arr[i]
			If we still can't reach it, were stuck! => -1

	Approach 2 - BFS
		BFS traversal will give shortest path
		Since edge cost is 1 for all
		Heavy on space
*/

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int reach = 0;
    int mx = 0;
    int jump = 0;
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
        // If i cannot reach position i
        if(reach < i)
        {
            // Make a jump from the max jump you saw before
            reach = mx;
            // If still cannot reach, -1
            if(reach < i)
            {
                ok = false;
                break;
            }
            // Reset max jump
            mx = i + arr[i];
            jump++;
        }
        else
            // Maximize jump
            mx = max(mx, i + arr[i]);
    }
    cout << (ok ? jump : -1) << endl;
}
