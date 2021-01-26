/*
	MISSING NUMBER IN ARRAY
	Array elements are from 1 to n
	Array length in n-1
*/

/*
	Approach 1 - O(n) or O(nlogn)
	Make frequency array/map
	Loop from 1 to n and see if number exists

	Approach 2 - O(n)
	Since numbers are supposed to be from 1 to n
	Their sum is n*(n+1)/2
	But actual sum will turn out to be a little less.
	Their difference is the missing number.
	n*(n+1)/2 - array_sum
*/

// Approach 1
int cnt[MAXN];
void cp()
{
    clr(cnt, 0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!cnt[i])
        {
            cout<<i<<endl;
            return;
        }
    }
}

// Approach 2
void cp()
{
    ll n;
    cin>>n;
    ll actual_sum = 0;
    ll expected_sum = n*(n+1)/2;
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        actual_sum += x;
    }
    cout<<expected_sum-actual_sum<<endl;
}