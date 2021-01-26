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
    int diff = k;
    set<int> unused;
    arr[0] = 1;
    bool add = true;
    for(int i = 2; i <= n; i++)
    {
        unused.insert(i);
    }
    for(int i = 1; i < n; i++)
    {
        if(diff)
        {
            if(add)
                arr[i] = arr[i - 1] + diff;
            else
                arr[i] = arr[i - 1] - diff;
            diff--;
            add = !add;
            unused.erase(arr[i]);
        }
        else
        {
            arr[i] = *unused.begin();
            unused.erase(unused.begin());
        }
    }
    for(int x : arr)
        cout << x << " ";

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