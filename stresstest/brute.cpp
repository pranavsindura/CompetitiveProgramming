#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll p, a[3];
        cin >> p;
        for(ll i = 0; i < 3; i++)
            cin >> a[i];

        ll ans = INT_MAX;
        for(ll i = 0; i < 3; i++)
        {
            if((p % a[i]) == 0)
            {
                ans = 0;
                break;
            }
            // else
            ans = min(ans, (a[i] - p % a[i] ) );
        }
        cout << ans << "\n";
    }
}