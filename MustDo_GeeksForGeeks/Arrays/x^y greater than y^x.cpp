/*
    Count Number of pairs such that x^y > y^x

    Approach 1 - O(nlogn)
    Write out different cases

    No solution for x == 1 or x == 0

    All pairs such that y > x satisfy equation
    exception - (2,3) and (2,4) do not satisfy

    Also
    (3,2) is an exception it does not satisfy y>x but it valid, count separately
    (x,1) is an exception for all x > 1
*/

int main()
{
    // FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, temp;
        cin >> n >> m;
        vector<int> a(n), b(m);
        int cnt[5] = {0};
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            if(b[i] < 5)
                cnt[b[i]]++;
        }
        ll count = 0;
        sort(all(b));
        for(int x : a)
        {
            if(x == 1)
                continue;
            int num = sz(b) - (upper_bound(all(b), x) - begin(b));
            count += num;
            count += cnt[1];
            if(x == 2)
                count -= (cnt[3] + cnt[4]);
            if(x == 3)
                count += cnt[2];

        }
        cout << count << endl;
    }
    return 0;
}