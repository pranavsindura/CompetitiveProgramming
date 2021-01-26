#include<bits/stdc++.h>
#define ll 			long long int
#define pi 			pair<int,int>
#define eps 		0.000000001
#define all(x) 		x.begin(), x.end()
#define allr(x) 	x.rbegin(), x.rend()
#define sz(x) 		((int)x.size())
#define ln(x) 		((int)x.length())
#define mp 			make_pair
#define pb 			push_back
#define ff 			first
#define ss 			second
#define endl 		'\n'
#define dbg(x) 		cout<<#x<<" "<<x<<endl
#define clr(x,v) 	memset(x, v, sizeof(x))
#define FASTIO 		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    string s;
    cin >> s;
    int n = ln(s);
    int pref[n + 1][3];
    clr(pref, 0);
    for(int i = 1; i <= n; i++)
    {
        for(char j = 'x'; j <= 'z'; j++)
        {
            pref[i][j - 'x'] = pref[i - 1][j - 'x'] + (s[i - 1] == j);
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        vector<int> cnt(3);
        for(int i = 0; i < 3; i++)
            cnt[i] = pref[r][i] - pref[l - 1][i];

        int len = r - l + 1;
        int lo = len / 3;
        int hi = (len + 2) / 3;

        bool ok = true;
        for(int c : cnt)
            if((c < lo) || (c > hi))
                ok = false;
        if(len < 3)
            ok = true;

        cout << (ok ? "YES\n" : "NO\n");
    }
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