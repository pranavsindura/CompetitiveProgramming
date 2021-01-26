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

int solve(vector<int> &arr, int i, int j, int count, int k)
{
    if(count > k)
        return 10000;
    if(i >= j)
        return count;
    else
    {
        if(arr[i] == arr[j])
            return solve(arr, i + 1, j - 1, count, k);
        else
            return min(solve(arr, i + 1, j, count + 1, k), solve(arr, i, j - 1, count + 1, k));
    }

}

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int ans = solve(arr, 0, n - 1, 0, k);
    if(ans > k)
        cout << "Too difficult";
    else if(ans == 0)
        cout << "Too easy";
    else
        cout << ans;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        // clr(dp, -1);
        cout << "Case " << i << ": ";
        cp();
        nl;
    }
    return 0;
}