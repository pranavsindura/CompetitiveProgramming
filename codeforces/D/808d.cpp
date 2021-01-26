#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;

    if(n == 1)
    {
        cout << "NO";
        return;
    }

    map<ll, int> left, right;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x, right[x]++;
    vector<ll> pref(n), suff(n);
    pref[0] = arr[0];
    for(int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + arr[i];
    suff[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + arr[i];
    bool ok = false;

    // start with empty partition on left and move 1 into it
    ll tl = 0, tr = suff[0];
    ll tdiff = tr;
    if(tdiff % 2 == 0)
    {
        ll half = tdiff / 2;
        if(right[half])
            ok = true;
    }

    for(int i = 0; i < n - 1; i++)
    {
        right[arr[i]]--;
        left[arr[i]]++;
        ll l = pref[i];
        ll r = suff[i + 1];
        if(l == r)
            ok = true;
        else
        {
            ll diff = abs(l - r);
            if(diff & 1)
                continue;
            ll half = diff / 2;
            if(l > r)
            {
                if(left[half] && i > 0)
                    ok = true;
            }
            else
            {
                if(right[half] && i + 1 < n - 1)
                    ok = true;
            }

        }
    }

    // start with empty on right, move one from left
    tl = pref[n - 1], tr = 0;
    tdiff = tl;
    if(tdiff % 2 == 0)
    {
        ll half = tdiff / 2;
        if(left[half])
            ok = true;
    }

    cout << (ok ? "YES" : "NO");
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}