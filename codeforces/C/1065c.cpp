#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 2e5 + 5;
ll freq[MAXN];

ll pref_sum(int l, int r)
{
    return (l ? freq[r] - freq[l - 1] : freq[r]);
}

void cp()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    clr(freq, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i], freq[arr[i]]++;

    for(int i = 1; i < MAXN; i++)
        freq[i] += freq[i - 1];

    sort(all(arr));
    int need = arr[0];

    int ans = 0;
    ll cost = 0;
    for(int i = 2e5; i >= need; i--)
    {
        // make cut at height i
        ll cnt = pref_sum(i + 1, MAXN-1);
        // cost of making cut at i will be the number of elements * 1 as we are making a cut in increments of 1
        // it will accumulate
        ll total = cost + cnt;
        if(total > k)
        {
            // make cut at i+1
            ans++;
            cost = cnt;
        }
        else
            cost += cnt;
    }
    if(cost)
    {
        ans++;
    }
    cout << ans << endl;
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