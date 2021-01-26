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
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));
    int ans = 0;
    bool ok = false;
    for(int b = 0; b < 10; b++)
    {
        int o = 0, z = 0;
        for(int x : arr)
            if(x & (1 << b))
                o++;
            else
                z++;
        if(o == z)
        {
            int temp = ans | (1 << b);
            vector<int> res;
            for(int x : arr)
                res.pb(x ^ temp);
            sort(all(res));
            bool equal = true;
            for(int i = 0; i < n; i++)
            {
                if(arr[i] != res[i])
                    equal = false;
            }
            if(equal)
            {
                ans = temp;
                ok = true;
                break;
            }
            else
                ans = temp;
        }
    }
    if(ok)
        cout << ans << endl;
    else
        cout << -1 << endl;
    // for(int i = 1; i <= 1024; i++)
    // {
    //     vector<int> res;
    //     for(int x : arr)
    //         res.pb(x ^ i);
    //     sort(all(res));
    //     bool equal = true;
    //     for(int i = 0; i < n; i++)
    //     {
    //         if(arr[i] != res[i])
    //             equal = false;
    //     }
    //     if(equal)
    //     {
    //         ans = i;
    //         break;
    //     }
    // }
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