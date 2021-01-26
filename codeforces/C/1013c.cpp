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
/*
Taking first n as x coord
WA, might have a consecutive segment of same numbers, picking that is better
Try all consecutive n segments
*/
void cp()
{
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));
    ll area = LLONG_MAX;
    for(int i = 0; i < n; i++)
    {
        //[i, i + n - 1]
        ll mnx = arr[i];
        ll mxx = arr[i + n - 1];
        ll mny = (!i ? arr[i + n] : arr[0]);
        ll mxy = arr.back();
        ll me = (mxx - mnx) * (mxy - mny);
        area = min(me, area);
    }
    cout << area << endl;
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