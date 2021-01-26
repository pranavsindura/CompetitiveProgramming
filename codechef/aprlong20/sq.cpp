#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n), res(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++)
    {
        int x = arr[i];
        int c = 0;
        while(x && x % 2 == 0)
            c++, x /= 2;
        // to handle the fact that 0 is div by 4
        if(x == 0)
            c = 2;
        res[i] = c;
    }
    ll ans = 0;
    int l = 0, r = 0, count = 0;
    while(r < n)
    {
        count += res[r];
        // cout<<l<<" "<<r<<": "<<count<<endl;
        if(count > 1)
        {
            ans += n - r;
            count -= res[l];
            if(l < r)
                l++, count -= res[r];
            else
                l++, r++;
        }
        else
            r++;
    }
    ll c = 0;
    for(int i = 0; i < n; i++)
    {
        if(abs(arr[i]) & 1)
            c++;
        else
        {
            ans += c * (c + 1) / 2;
            c = 0;
        }
    }
    ans += c * (c + 1) / 2;
    printf("%lld\n", ans);
}

int main()
{
    int t;
    t = 1;
    scanf("%d", &t);
    while(t--)
    {
        cp();
    }
    return 0;
}