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
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void cp()
{
    int n;
    int d;
    while(cin >> n >> d)
    {
    	d = abs(d);
        if(!n && !d)
            break;
        vector<int> cnt(100, 0);
        for(int i = 0; i < sz(prime); i++)
        {
            int p = 0;
            int temp = n;
            while(temp)
            {
                temp /= prime[i];
                p += temp;
            }
            cnt[prime[i]] = p;
        }
        vector<int> fac;
        while(d % 2 == 0)
            fac.pb(2), d /= 2;
        for(int i = 3; i <= sqrt(d); i += 2)
        {
            while(d % i == 0)
                fac.pb(i), d /= i;
        }
        if(d > 1)
            fac.pb(d);

        bool ok = true;
        for(int x : fac)
        {
            if(x < 100 && cnt[x])
                cnt[x]--;
            else
                ok = false;
        }
        if(ok)
        {
            ll ans = 1;
            for(int x : prime)
            {
                ans *= 1LL*(cnt[x] + 1LL);
            }
            cout << ans << endl;
        }
        else
            cout << 0 << endl;
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