/*
	Given 2 arrays, find if there is a pair such that swapping Ai and Bj that new Array sums become equal
*/
/*
	Approach 1 -
	Assume sum1 < sum2
	After swapping we want

	sum1 - Ai + Bj == sum2 - Bj + Ai
	2(Bj - Ai) = sum2 - sum1

	Let, diff = sum2 - sum1

	Bj - Ai = diff/2 **If difference is odd, no pair exists**
	Bj = Ai + diff/2

	Find if for each Ai, Ai + diff/2 exists in Array B
*/
void cp()
{
    int n, m;
    int sum_a = 0, sum_b = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a)
        cin >> x, sum_a += x;
    for(int &x : b)
        cin >> x, sum_b += x;
    int diff = sum_b - sum_a;
    if(abs(diff) % 2)
    {
        cout << -1 << endl;
        return;
    }
    diff = diff / 2;
    map<int, int> fb;
    for(int x : b)
        fb[x]++;
    int cnt = 0;
    for(int x : a)
    {
        int need = x + diff;
        if(fb[need])
            cnt = 1;
    }
    if(cnt)
        cout << cnt << endl;
    else
        cout << -1 << endl;
}