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
const int MAXN = 4e5 + 5;

vector<int> pos, nxt, prv;
void make_bigger_smaller(vector<int> &arr, vector<int> &g, vector<int> &s)
{
    int n = sz(arr);
    g = vector<int>(n, -1);
    s = vector<int>(n, -1);
    pos.resize(n);
    nxt.resize(n);
    prv.resize(n);
    for(int i = 0; i < n; i++)
        pos[arr[i]] = i, nxt[i] = i + 1, prv[i] = i - 1;

    for(int i = n - 1; i >= 0; i--)
    {
        if(nxt[arr[i]] != n)
            g[i] = pos[nxt[arr[i]]];
        if(prv[arr[i]] != -1)
            s[i] = pos[prv[arr[i]]];
        if(nxt[arr[i]] != n)
            prv[nxt[arr[i]]] = prv[arr[i]];
        if(prv[arr[i]] != -1)
            nxt[prv[arr[i]]] = nxt[arr[i]];
    }
}

bool check(vector<int> &text, vector<int> &g, vector<int> &s, int i, int k)
{
    if(~g[k] && text[i - (k - g[k])] < text[i])
        return false;
    if(~s[k] && text[i - (k - s[k])] > text[i])
        return false;
    return true;
}

vector<int> arr, seq, failure, g, s, idx;
void cp()
{
    int n, m;
    cin >> m >> n;

    seq.resize(m);
    for(int i = 0, x; i < m; i++)
        cin >> x, seq[x - 1] = i;

    arr.resize(n);
    for(int &x : arr)
        cin >> x;

    // make_perm(arr);
    make_bigger_smaller(seq, g, s);

    failure.resize(m);
    failure[0] = 0;

    // print(seq, g, s);

    for(int i = 1, k = 0; i < m; i++)
    {
        while(k > 0 && !check(seq, g, s, i, k))
            k = failure[k - 1];
        if(check(seq, g, s, i, k))
            k++;
        failure[i] = k;
    }

    for(int i = 0, k = 0; i < n; i++)
    {
        while(k > 0 && !check(arr, g, s, i, k))
            k = failure[k - 1];
        if(check(arr, g, s, i, k))
            k++;
        if(k == m)
            idx.pb(i - m + 1), k = failure[k - 1];
    }
    cout << sz(idx) << endl;
    for(int i = 0; i < sz(idx); i++)
    {
        if(i)
            cout << " ";
        cout << idx[i] + 1;
    }
    cout << endl;
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