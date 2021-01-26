/*
	Find Largest Number with 'N' digits and Digit Sum 'S'
*/
/*
	Approach 1 - Try every number of length N O(10^n)

	Approach 2 - Greedy O(n)
		First handle base cases
		1. Sum == 0 and n > 1, not possible
		2. Sum > 9 * n, not possible

		Now greedily place the highest digit that the sum can accommodate for each i => [1, n]

		If the digit ever falls below 0 then stop

		Check if sum == 0: you have found your number
		else: answer is not possible
*/
// Approach 2
void cp()
{
    int n, sum;
    cin >> n >> sum;

    if(sum == 0 && n > 1)
    {
        cout << -1 << endl;
        return;
    }
    else if(n * 9 < sum)
    {
        cout << -1 << endl;
        return;
    }

    string ans;
    int digit = 9;
    
    for(int i = 0; i < n; i++)
    {
        if(digit < 0)
            break;
        if(sum >= digit)
            sum -= digit, ans += char(48 + digit);
        else
            digit--, i--;
    }
    if(sum == 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
