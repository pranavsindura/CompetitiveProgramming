#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
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

void cp()
{
    int n, s;
    cin >> n >> s;
    if(s >= 2 * n)
    {
        int each = s / n;
        vector<int> arr(n);
        for(int i = 0; i < n - 1; i++)
            arr[i] = each;
        arr[n - 1] = s - (n - 1) * each;
        cout << "YES\n";
        for(int x : arr)
            cout << x << " ";
        cout << endl;
        cout << 1;
    }
    else
    {
        cout << "NO";
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