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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, a, b, k;
    string s;
    cin >> n >> a >> b >> k >> s;
    int l = 0, r = 0;
    int slots = 0;
    vector<int> slot_pos;
    while(true)
    {
        while(l < n && s[l] == '1')
            l++;
        if(l == n)
            break;
        r = l;
        while(r + 1 < n && s[r + 1] == '0')
            r++;
        int len = r - l + 1;
        slots += len / b;
        if(len >= b)
            for(int i = l; i + b - 1 <= r; i += b)
                slot_pos.pb(i + b - 1);
        l = r + 1;
    }
    
    vector<int> ans;
    int need_slots = slots - a + 1;

    while(need_slots > 0 && !slot_pos.empty())
    {
        ans.pb(slot_pos.back() + 1);
        slot_pos.pop_back();
        need_slots--;
    }
    cout << sz(ans) << endl;
    for(int x : ans)
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