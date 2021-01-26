#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, mi, ma;
        cin >> n;
        vector<int> left, right;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            left.push_back(l);
            right.push_back(r);
        }
        mi = *min_element(all(left));
        ma = *max_element(all(right));
        sort(all(left));
        sort(all(right));
        int a = 1, i = 1, j = 0, b = 1, z = INT_MAX;
        while(i < n && j < n)
        {
            if(left[i] <= right[j])
            {
                a++;
                i++;
                b = max(a, b);
            }
            else
            {
                a--;
                z = min(z, a);
                j++;
            }
        }
        if(b == n)
            cout << -1 << endl;
        else if(b == 1)
            cout << 0 << endl;
        else
            cout << z << endl;
    }
}