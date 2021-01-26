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
int pref[27][2005];
int sum(int num, int l, int r)
{
    return (l ? pref[num][r] - pref[num][l - 1] : pref[num][r]);
}
void calc(vector<int> &arr)
{
    memset(pref, 0, sizeof(pref));
    for(int num = 1; num <= 26; num++)
    {
        for(int i = 0; i < sz(arr); i++)
        {
            pref[num][i] = (i ? pref[num][i - 1] + (arr[i] == num) : arr[i] == num);
        }
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
    {
        cin >> x;
    }
    calc(arr);
    int ans = 0;
    for(int i=1;i<=26;i++)
        ans = max(ans, pref[i][n-1]);
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j < n - 1; j++)
        {
            int mid = INT_MIN;
            for(int k = 1; k <= 26; k++)
            {
                mid = max(mid, sum(k, i, j));
            }
            int ends = INT_MIN;
            for(int k = 1; k <= 26; k++)
            {
                ends = max(ends, min(sum(k, 0, i - 1), sum(k, j + 1, n - 1)));
            }
            ans = max(ans, mid + 2 * ends);
        }
    }
    cout << ans << endl;
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