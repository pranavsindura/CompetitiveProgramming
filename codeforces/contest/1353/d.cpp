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

struct cmp
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
    {
        int lena = a.second - a.first + 1;
        int lenb = b.second - b.first + 1;
        if (lena == lenb) return a.first < b.first;
        return lena > lenb;
    }
};


void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    set<pii, cmp> s;
    s.insert({1, n});
    for(int c = 1; c <= n; c++)
    {
        pii x = *s.begin();
        s.erase(s.begin());
        int len = x.ss - x.ff + 1;
        int l = x.ff, r = x.ss;
        int mid;
        if(len % 2 == 0)
            mid = (l + r - 1) / 2;
        else
            mid = (l + r) / 2;
        arr[mid] = c;
        if(mid - x.ff)
            s.insert({x.ff, mid - 1});
        if(x.ss - mid)
            s.insert({mid + 1, x.ss});
    }
    for(int c = 1; c <= n; c++)
    	cout<<arr[c]<<" ";
    cout<<endl;
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