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
const int MAXN = 1e5 + 5;
int t[4 * MAXN][26];
string s;
void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        for(int i = 0; i < 26; i++)
            t[v][i] = 0;
        t[v][s[tl] - 'a']++;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        for(int i = 0; i < 26; i++)
            t[v][i] = 0;
        for(int i = 0; i < 26; i++)
            t[v][i] = t[v << 1][i] + t[v << 1 | 1][i];
    }
}

void update(int v, int tl, int tr, int pos, char val)
{
    if(tl == tr)
    {
        t[v][s[tl] - 'a'] = 0;
        t[v][val - 'a']++;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        for(int i = 0; i < 26; i++)
            t[v][i] = t[v << 1][i] + t[v << 1 | 1][i];
    }
}

vector<int> query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return vector<int>(26, 0);

    if(tl == l && tr == r)
        return vector<int>(t[v], t[v] + 26);
    else
    {
        int tm = (tl + tr) >> 1;
        vector<int> left = query(v << 1, tl, tm, l, min(r, tm));
        vector<int> right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        for(int i = 0; i < 26; i++)
            left[i] += right[i];
        return left;
    }
}

void cp()
{
    int n, q;
    cin >> n >> q >> s;
    build(1, 0, n - 1);
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int d;
            char p;
            cin >> d >> p;
            update(1, 0, n - 1, d - 1, p);
            s[d - 1] = p;
        }
        else
        {
            int l, r, k;
            cin >> l >> r >> k;
            vector<int> op = query(1, 0, n - 1, l - 1, r - 1);
            char res;
            for(int i = 0; i < 26 && k > 0; i++)
            {
                k -= op[i], res = char(97 + i);
            }
            cout << res << endl;
        }

    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}