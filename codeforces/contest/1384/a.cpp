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
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<string> res;
    string s(200, 'a');
    res.pb(s);
    for(int i = 0; i < n; i++)
    {
        string t;
        for(int j = 0; j < arr[i]; j++)
            t += res[i][j];
        char p = 'a';
        for(char x = 'a'; x <= 'z'; x++)
            if(x != res[i][arr[i]])
                p = x;
        for(int j = arr[i]; j < 200; j++)
        {
            t += p;
        }
        res.pb(t);
    }
    for(string x : res)
        cout << x << endl;
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