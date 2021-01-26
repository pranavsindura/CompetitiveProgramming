
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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll sum(int l, int r, vector<ll> &pref)
{
    return (l ? pref[r] - pref[l - 1] : pref[r]);
}

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<ll> less, more;
    bool has_zero = false;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x < 0)
            less.pb(x);
        else if(x > 0)
            more.pb(x);
        else
            has_zero = true;
    }

    int pos_zero = 0;
    vector<ll> diff;

    // If originally did not have zero, we add one. Increase window length
    if(!has_zero)
        k++;

    // Find distances for negative numbers
    for(int i = 1; i < sz(less); i++)
    {
        diff.pb(abs(less[i] - less[i - 1]));
    }
    if(sz(less))
        diff.pb(abs(less.back()));

    // Add zero
    pos_zero = sz(diff);
    diff.pb(0);


    // Find distances for positive numbers
    if(sz(more))
        diff.pb(abs(more[0]));

    for(int i = 1; i < sz(more); i++)
    {
        diff.pb(abs(more[i] - more[i - 1]));
    }
    // Forming Prefix Array
    for(int i = 1; i < sz(diff); i++)
        diff[i] += diff[i - 1];
    // Get window of size k
    int i = 0, j = 0;
    while(j - i + 1 < k && j < sz(diff))
        j++;

    // Move window to include zero
    while(j < pos_zero)
        i++, j++;

    ll ans = INT_MAX;

    while(i <= pos_zero && j < sz(diff))
    {
    	// Numbers on the Left of zero
        ll left = sum(i, pos_zero, diff);
        // Numbers on the right of zero
        ll right = sum(pos_zero, j, diff);

    	// Either you visit some numbers on right twice and on left once
    	// Or you visit some numbers on left twice and on right once
        ans = min({ans, left * 2 + right, right * 2 + left});

        // Next window
        i++, j++;
    }
    cout << ans;
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