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

void smoothen(int l, int r, vector<int> &arr)
{
    int mid = (l + r) / 2;
    int left = arr[l];
    int right = arr[r];
    for(int i = l + 1; i <= mid; i++)
    {
        arr[i] = left;
    }
    for(int i = mid+1; i < r; i++)
    {
        arr[i] = right;
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int max_unstable = 0;
    int unstable = 0;
    int l, r;
    for(int i = 1; i < n - 1; i++)
    {
        if(arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
        {
            unstable++;
            max_unstable = max(max_unstable, unstable);
            if(unstable == 1)
                l = i - 1;
            r = i + 1;
        }
        else
        {
            if(unstable)
                smoothen(l, r, arr), unstable = 0;
        }
    }
    if(unstable)
        smoothen(l, r, arr);
    cout << (max_unstable + 1) / 2 << endl;
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