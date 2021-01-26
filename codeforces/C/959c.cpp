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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    if(n < 6)
    {
        cout << -1 << endl;
    }
    else
    {
    	// For Wrong Answer
        // Join 1 2
        cout << "1 2\n";
        int left = n - 2;
        int v = 3;
        int low_half = left / 2;
        int upp_half = (left + 1) / 2;
        // Join Half nodes with 1
        for(int i = 0; i < low_half; i++)
            cout << 1 << " " << v++ << endl;
        // Join rest Half with 2
        for(int i = 0; i < upp_half; i++)
            cout << 2 << " " << v++ << endl;
        // Algorithm will give answer n/2 but actual answer is 2 -> {1, 2}
    }
    // For Correct Answer
    // Simply form a chain
    for(int i = 1; i <= n - 1; i++)
    {
        cout << i << " " << i + 1 << endl;
    }
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