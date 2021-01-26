#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, c;
        cin >> n >> c;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(all(arr));
        ll lo = 0, hi = 1000000000;
        ll ans;
        while(lo < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            int count = 1;
            ll p = arr[0];
            for(int i = 1; i < n; i++)
            {
                if(arr[i] - p >= mid)
                {
                	p = arr[i];
                    count++;
                    if(count == c)
                    	break;
                }
            }
            if(count == c)
                ans = mid, lo = mid + 1;
            else
                hi = mid;

        }
        cout << ans << endl;
    }
    return 0;
}