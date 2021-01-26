#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> asc(n), desc(n);
    iota(all(asc), 1);
    iota(all(desc), 1), reverse(all(desc));

    int l = 0;
    while(l < ln(s))
    {
        while(l < ln(s) && s[l] == '<') l++;
        if(l == ln(s)) break;

        int r = l;
        while(r + 1 < ln(s) && s[l] == s[r + 1]) r++;

        r++;
        int m = r - l + 1;
        for(int i = 0; i < m / 2; i++)
            swap(asc[l + i], asc[l + m - i - 1]);

        l = r;
    }

    l = 0;
    while(l < ln(s))
    {
        while(l < ln(s) && s[l] == '>') l++;
        if(l == ln(s)) break;

        int r = l;
        while(r + 1 < ln(s) && s[l] == s[r + 1]) r++;

        r++;
        int m = r - l + 1;
        for(int i = 0; i < m / 2; i++)
            swap(desc[l + i], desc[l + m - i - 1]);

        l = r;
    }

    for(int x : desc)
        cout << x << " ";
    cout << endl;
    
    for(int x : asc)
        cout << x << " ";
    cout << endl;
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

