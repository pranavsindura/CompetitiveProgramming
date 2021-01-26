#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
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
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;

int main()
{
    freopen("in", "w", stdout);
    FASTIO;
    srand(time(NULL));
    int test = 1;
    // cout << test << endl;
    while(test--)
    {
        int n = 20;
        cout << n << endl;
        for(int i = 0; i < n; i++)
        {
            cout << rand() % 21+1 << " ";
        }
        cout << endl;
    }
    return 0;
}