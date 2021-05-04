#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pii pair<int, int>
#define inf INT_MAX
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define maxn 100000+5
#define eps 1e-10
#define ff first
#define ss second
#define sz size
#define lnt length
#define here(x) cout << #x << " is " << x << endl;
#define setv(x, v) memset(x, v, sizeof(x))
#define prec(x) cout << fixed << setprecision(x);
#define fio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve()
{
    int n;
    cin >> n;
    vector<int>v(n), l(n), r(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<pii>pref, suff;
    pref.pb({INT_MAX, -1});
    // l[0] = -1;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = pref.sz() - 1; j >= 0; j--)
        {
            if(v[i] <= pref[j].ff)
            {
                // cnt = pref.sz() - j - 1;
                break;
            }
            cnt++;
            pref.pop_back();
        }
        // while(cnt > 0)
        //     pref.pop_back(), cnt--;
        l[i] = pref.back().ss;
        pref.pb({v[i], i});
    }
    suff.pb({inf, n});
    // r[n - 1] = n - 1;
    for(int i = n - 1; i >= 0; i--)
    {
        int cnt = 0;
        for(int j = suff.sz() - 1; j >= 0; j--)
        {
            if(v[i] <= suff[j].ff)
            {
                // cnt = suff.sz() - j - 1;
                break;
            }
            cnt++;
            suff.pop_back();
        }
        // while(cnt > 0)
        //     suff.pop_back(), cnt--;
        r[i] = suff.back().ss;
        suff.pb({v[i], i});
    }
    for(int i = 0; i < n; i++)
        cout << l[i] + 1 << " " << r[i] - 1 << endl;
}

int main()
{
    fio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}