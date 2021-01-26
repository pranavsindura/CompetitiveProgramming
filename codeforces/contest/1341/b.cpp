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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);

int sum(int l, int r, vector<int> &arr)
{
    return (l ? arr[r] - arr[l - 1] : arr[r]);
}

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<int> peak(n, 0);
    for(int i = 1; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
            peak[i] = 1;
    }
    int st, en, mx = INT_MIN;
    for(int i = 1; i < n; i++)
        peak[i] += peak[i - 1];
    for(int i = 0; i < n && i+k-2 < n-1; i++)
    {
        int p = sum(i + 1, i + k - 2, peak);
        if(p > mx)
        {
            mx = p;
            st = i + 1, en = i + k;
        }
    }
    cout << mx+1 << " " << st << endl;
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