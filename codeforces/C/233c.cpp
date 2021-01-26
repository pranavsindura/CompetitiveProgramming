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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
using namespace std;

int adj[105][105];

void cp()
{
    int cyc;
    cin >> cyc;
    int n = 3;
    int count = 0;
    while(count < cyc)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(adj[i][j])
                    continue;
                int common = 0;
                for(int k = 0; k < n; k++)
                    common += (adj[i][k] & adj[j][k]);
                if(count + common <= cyc)
                    adj[i][j] = adj[j][i] = 1, count += common;
            }
        }
        if(count < cyc)
            n++;
    }
    cout << n << endl;
    for(int i = 0; i < n; i++, cout << endl)
        for(int j = 0; j < n; j++)
            cout << adj[i][j];
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