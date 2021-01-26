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
ll sum, sz = 1;
vector<pair<ll, ll>> arr;
void cp()
{
    int t;
    cin >> t;
    if(t == 1)
    {
        ll a, x;
        cin >> a >> x;
        arr[a - 1].ss += x;
        sum += a * x;
    }
    else if(t == 2)
    {
        int k;
        cin >> k;
        sz++;
        arr.pb({k, 0});
        sum += k;
    }
    else
    {
        sz--;
        pi last = arr.back();
        arr.pop_back();
        sum -= last.ff + last.ss;
        arr.back().ss += last.ss;
    }
    double avg = double(sum) / double(sz);
    cout << setprecision(12) << fixed << avg << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    arr.pb({0, 0});
    while(t--)
    {
        cp();
    }
    return 0;
}