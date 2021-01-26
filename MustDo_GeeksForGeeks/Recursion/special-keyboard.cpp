/*
	Special Keyboard
	Type Maximum number of 'A'
	1 - Press 'A'
	2 - Ctrl A
	3 - Ctrl C
	4 - Ctrl V
*/
/*
	Approach 1 - There is a pattern of linear recurrence
	Go n-5 steps back and then press Ctrl C, Ctrl V, Ctrl V, Ctrl V, Ctrl V  => 4 * f(n-5)
	Go n-4 steps back and then press Ctrl C, Ctrl V, Ctrl V, Ctrl V => 3 * f(n-4)

	for n < 7 it is just n
*/
int rec(int n)
{
    if(n < 7)
    {
        return n;
    }
    else
    {
        return max(
                   4 * rec(n - 5),
                   3 * rec(n - 4)
               );
    }
}

void cp()
{
    int n;
    cin >> n;
    cout << rec(n) << endl;
}