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
    vector<int> bit(32);
    for(int b = 0; b < 32; b++)
        for(int x : arr)
            if((x >> b) & 1)
                bit[b]++;
    int e = 0;
    bool first = false;
    for(int b = 31; b >= 0; b--)
    {
        if(bit[b] % 2 == 0)
            e++;
        else
        {
            int half = bit[b] / 2;
            if(half & 1)
            {
                if((n - bit[b]) & 1)
                    first = true;
            }
            else
                first = true;
            break;
        }
    }
    if(e == 32)
        cout << "DRAW\n";
    else
    {
        cout << (first ? "WIN\n" : "LOSE\n");
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