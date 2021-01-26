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
#define dbg(x) cout<<#x<<" "<<x<<endl
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
    vector<int> arr(2 * n);
    vector<int> odd, even;
    for(int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
        if(arr[i] & 1)
            odd.pb(i + 1);
        else
            even.pb(i + 1);
    }
    if(sz(odd) % 2 && sz(even) % 2)
    {
        odd.pop_back();
        even.pop_back();
    }
    else
    {
        if(sz(odd))
        {
            odd.pop_back();
            odd.pop_back();
        }
        else
        {
            even.pop_back();
            even.pop_back();
        }
    }

    for(int i = 0; i < sz(odd) - 1; i+=2)
    {
        cout << odd[i] << " " << odd[i + 1] << endl;
    }
    for(int i = 0; i < sz(even) - 1; i+=2)
    {
        cout << even[i] << " " << even[i + 1] << endl;
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