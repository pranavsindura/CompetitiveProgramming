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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

string s;
map<int, int> fact[32];
void factorise(int x, map<int, int> &cnt)
{
    while(x % 2 == 0)
        cnt[2]++, x /= 2;
    for(int i = 3; i <= sqrt(x); i += 2)
        while(x % i == 0)
            cnt[i]++, x /= i;
    if(x > 1)
        cnt[x]++;
}

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

void init()
{
    for(int i = 2; i < 32; i++)
        fact[i] = fact[i - 1], factorise(i, fact[i]);
}

void cp()
{
    string t = s;
    sort(all(t));
    vector<int> freq(26);
    for(char x : t)
        freq[x - 'a']++;
    int n = ln(s);

    function<ll(int, vector<int>)> f = [&](int picked, vector<int> cnt)
    {
        map<int, int> tot = fact[n - picked - 1];
        for(int x : cnt)
        {
            for(auto &y : fact[x])
                tot[y.ff] -= y.ss;
        }
        ll res = 1;
        for(auto &x : tot)
            res *= fpow(x.ff, x.ss);
        return res;
    };

    ll ans = 0;
    ll lo = 1, hi = f(-1, freq);

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll sum = 0;
        // generate the mid-th permutation
        vector<int> cnt = freq;
        vector<bool> picked(n);
        string gen;

        // dbg(mid);
        for(int i = 0; i < n; i++)
        {
            // decide position i
            int place = -1;
            for(int j = 0; j < 26; j++)
            {
                if(cnt[j])
                {
                    cnt[j]--;
                    if(sum + f(i, cnt) < mid)
                        sum += f(i, cnt);
                    else
                    {
                        place = j;
                        break;
                    }
                    cnt[j]++;
                }
            }
            gen += char(97 + place);
        }
        if(gen <= s)
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    string a;
    while(ans)
        a += char(48 + ans % 10), ans /= 10;
    while(sz(a) < 10)
        a += ' ';
    reverse(all(a));
    cout << a << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    while(cin >> s && s[0] != '#')
    {
        cp();
    }
    return 0;
}