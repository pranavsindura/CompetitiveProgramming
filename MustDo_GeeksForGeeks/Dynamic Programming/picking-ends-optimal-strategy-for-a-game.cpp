/*
	Optimal Strategy Game Picking from Ends

	
	Given an array
	Two players play a game alternately, at every step player can pick a number from the either ends
	Each player plays optimally
	If you go first, what is the maximum sum of elements you can get
*/
/*
	Approach - Recursion + Memo O(n^2) space, O(n^2) time
		Since both players optimally, you need to maximise your sum, and then minimize opponents sum
		We can hold the pointers of the ends of the arrays and try to pick both and see which results
		in our maximum sum and their minimum

		We can have a pair of player0 and player1 values for every recursion

		We can add memo
*/

int n;
int arr[105];
pi dp[105][105][2];
// Player 0, Player 1
// PLayer 0 goes first
pi solve(int i, int j, int player)
{
    if(i > j)
        return {0, 0};
    if(i == j)
    {
        // last turn
        if(player == 0)
            return {arr[i], 0};
        else
            return {0, arr[i]};
    }

    pi &ret = dp[i][j][player];
    if(ret.ff != -1)
        return ret;

    //pick arr[i]
    pi choice1 = solve(i + 1, j, player ^ 1);
    if(player == 0)
        choice1.ff += arr[i];
    else
        choice1.ss += arr[i];

    //pick arr[j]
    pi choice2 = solve(i, j - 1, player ^ 1);
    if(player == 0)
        choice2.ff += arr[j];
    else
        choice2.ss += arr[j];

    if(player == 0)
    {
        //maximise first
        if(choice1.ff > choice2.ff)
            return ret = choice1;
        else if(choice1.ff < choice2.ff)
            return ret = choice2;
        // If they are same, minimise opponents turn
        else if(choice1.ss > choice2.ss)
            return ret = choice2;
        else
            return ret = choice1;

    }
    else
    {
        // maximise second
        if(choice1.ss > choice2.ss)
            return ret = choice1;
        else if(choice1.ss < choice2.ss)
            return ret = choice2;
        // If they are same, minimise opponents turn
        else if(choice1.ff > choice2.ff)
            return ret = choice2;
        else
            return ret = choice1;
    }
}

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j][0] = {-1, -1}, dp[i][j][1] = {-1, -1};


    pi ans = solve(0, n - 1, 0);
    cout << ans.ff << endl;
}
