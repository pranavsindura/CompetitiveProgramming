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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    vector<int> prime = {2, 3, 5, 7, 4, 9, 25, 49, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int cnt = 0;
    for(int i = 0; i < sz(prime); i++)
    {
        cout << prime[i] << endl;
        cout.flush();
        string s;
        cin >> s;
        cnt += (s == "yes");
    }
    cout << (cnt <= 1 ? "prime\n" : "composite\n");
    cout.flush();
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