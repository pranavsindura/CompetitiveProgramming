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
const int MAXN = 1e6 + 5;


void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr), [](int a, int b)
    {
        int x = ((a + 9) / 10) * 10, y = ((b + 9) / 10) * 10;

        if(a % 10 == 0)
            x += 10;
        if(b % 10 == 0)
            y += 10;
        x = min(x, 100);
        y = min(y, 100);
        return (x - a) < (y - b);
    });
    bool done = false;
    while(k > 0 && !done)
    {
        done = true;
        for(int i = 0; i < n; i++)
        {
            int x = ((arr[i] + 9) / 10) * 10;
            if(arr[i] % 10 == 0)
                x += 10;
            x = min(x, 100);
            int need = x - arr[i];
            if(need > k || need == 0)
                continue;
            else
            {
                k -= need;
                arr[i] = x;
                done = false;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += arr[i] / 10;
    cout << ans << endl;
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