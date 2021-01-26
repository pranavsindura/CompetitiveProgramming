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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    vector<int> pos;
    for(int i = 0; i < n; i++)
        if(s[i] == '1')
            pos.push_back(i + 1);
    int last_one = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0')
        {
            // try to place one
            // cout << last_one << " ";
            if(last_one)
            {
                auto it = upper_bound(all(pos), i);
                if(it == pos.end())
                {
                    int me = i + 1;
                    if(me - last_one > k)
                        ans++, last_one = i + 1;
                }
                else
                {
                    int right = *it;
                    // cout << right;
                    int me = i + 1;
                    if(me - last_one > k && right - me > k)
                        ans++, last_one = i + 1;
                }
            }
            else
            {
                auto it = upper_bound(all(pos), i);
                if(it == pos.end())
                {
                    ans++, last_one = i + 1;
                }
                else
                {
                    int right = *it;
                    // cout << right;
                    int me = i + 1;
                    if(right - me > k)
                        ans++, last_one = i + 1;
                }
            }
            // cout << endl;
        }
        else
            last_one = i + 1;
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