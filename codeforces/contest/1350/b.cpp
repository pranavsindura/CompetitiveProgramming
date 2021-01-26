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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int ans[n + 1];

    for(int i = 1; i <= n; i++)
    {
        ans[i] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + i; j <= n; j += i)
        {
            if(arr[i-1] < arr[j-1])
                ans[j] = max(ans[j], ans[i] + 1);
        }
    }
    cout << *max_element(ans + 1, ans + n + 1) << endl;
}

int main()
{
    FASTIO;
    // init();
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}