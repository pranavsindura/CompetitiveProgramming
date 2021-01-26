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
#define dblout(x) cout << setprecision(x) << fixed;
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
    int ones = 0, zero = 0;
    for(int x : arr)
        if(x)
            ones++;
        else
            zero++;
    int half = n / 2;
    if(half & 1)
    {
        if(zero >= n / 2)
        {
            cout << n / 2 << endl;
            for(int i = 0; i < n / 2; i++)
                cout << 0 << " ";
            cout << endl;
        }
        else
        {
            if(ones > n / 2)
            {
                cout << half + 1 << endl;
                for(int i = 0; i < half + 1; i++)
                    cout << 1 << " ";
                cout << endl;
            }
            else
            {
                cout << half + 1 << endl;
                for(int i = 0; i < n / 2; i++)
                    cout << 1 << " ";
                cout << 0;
                cout << endl;
            }
        }
    }
    else
    {
        if(ones >= n / 2)
        {
            cout << n / 2 << endl;
            for(int i = 0; i < n / 2; i++)
                cout << 1 << " ";
            cout << endl;
        }
        else
        {
            cout << n / 2 << endl;
            for(int i = 0; i < n / 2; i++)
                cout << 0 << " ";
            cout << endl;
        }
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