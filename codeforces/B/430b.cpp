#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n, k, ball;
    cin >> n >> k >> ball;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] != arr[i + 1])
            continue;
        else if(arr[i] != ball)
            continue;
        int destroyed = 2;
        int count = 0;
        int l = i - 1, r = i + 2;
        while(l >= 0 && r < n)
        {
            if(arr[l] != arr[r])
                break;
            count = 2;
            while(true)
            {
                if(r + 1 < n && arr[r + 1] == arr[r])
                    count++, r++;
                else
                    break;
            }
            while(true)
            {
                if(l - 1 >= 0 && arr[l - 1] == arr[l])
                    count++, l--;
                else
                	break;
            }
            if(count > 2)
            	destroyed += count;
            else
            	break;
            l--, r++;
        }
        ans = max(ans, destroyed);
    }
    cout << ans;
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