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
    string s;
    cin >> n >> s;
    int op = 0;
    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        int l = (i - 1 + n) % n;
        if(s[l] != s[i])
        {
            pos = i;
            break;
        }
    }
    string t;
    for(int i = 0; i < n; i++)
        t += s[(pos + i) % n];

    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(t[i] == t[i - 1])
            cnt++;
        else
            op += cnt / 3, cnt = 1;
    }
    op += cnt / 3;
    if(cnt == n)
        op += (n % 3 > 0);
    cout << op << endl;
}

int main()
{
    FASTIO;
    // time_t t1, t2;
    // t1 = clock();
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    // t2 = clock();
    // cerr << endl << "time taken: " << (long double) (t2 - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}