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

int solve(int l, int r, string &s, char c)
{
    if(l > r)
        return 0;
    if(l == r)
        return s[l] != c;

    int m = (l + r) / 2;

    int choice1 = 0, choice2 = 0;
    // Make Left half equal to ccccc...
    for(int i = l; i <= m; i++)
        if(s[i] != c)
            choice1++;
    // And right half c+1 good
    choice1 += solve(m + 1, r, s, c + 1);

    // OR

    // Make Right half equal to ...ccccc
    for(int i = m + 1; i <= r; i++)
        if(s[i] != c)
            choice2++;
    // Make Left half c+1 good
    choice2 += solve(l, m, s, c + 1);


    return min(choice1, choice2);
}

void cp()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = solve(0, n - 1, s, 'a');

    cout << ans << endl;
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