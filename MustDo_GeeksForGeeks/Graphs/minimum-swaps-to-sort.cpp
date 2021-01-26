/*
	Minimum swaps to sort array
*/

/*
	Approach -
	The elements which are to be swapped form a cycle

	1 6 3 2 4
	1 stays

	6 goes to 4
	4 goes to 2
	2 goes to 6
	end cycle

	3 stays

	We store arr[i] and i as a pair and sort them -> arr_pos[i] = {arr[i], i}

	Then loop from [0, n)
	If arr_pos[i].second = i then it is in correct position
	else we go to the number who is there in the arr_pos[i].second-th position as it is part of the cycle

	We can count the length of the cycle and length-1 swaps are needed for each cycle
*/

int minSwaps(int arr[], int N)
{
    pair<int, int> arr_pos[N];
    for(int i = 0; i < N; i++)
        arr_pos[i] = {arr[i], i};
    sort(arr_pos, arr_pos + N);

    bool vis[N];
    memset(vis, false, sizeof vis);
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        if(vis[i] || arr_pos[i].second == i)
            continue;
        int pos = i;
        int comp_size = 0;
        while(!vis[pos])
        {
            vis[pos] = true;
            pos = arr_pos[pos].second;
            comp_size++;
        }
        cnt += comp_size - 1;
    }
    return cnt;
}
