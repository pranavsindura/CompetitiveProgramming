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
    int mx = 0;
    vector<int> cnt(26, 0);
    for(char x : s)
        cnt[x - 'a']++;
    for(int len = n; len > 0; len--)
    {
        vector<bool> pos(len, false);
        vector<int> cycle_len;
        for(int i = 0; i < len; i++)
        {
            if(pos[i])
                continue;
            cycle_len.pb(0);
            int j = i;
            while(!pos[j])
            {
                cycle_len.back()++;
                pos[j] = true;
                j = (j + k) % len;
            }
        }

        bool can = true;
        vector<int> freq(cnt);
        sort(all(cycle_len));
        sort(all(freq));
        while(!cycle_len.empty())
        {
            if(freq.back() < cycle_len.back())
            {
                can = false;
                break;
            }
            else
            {
                freq.back() -= cycle_len.back();
                cycle_len.pop_back();
                sort(all(freq));
            }
        }
        if(can)
        {
            cout<<len<<endl;
            return;
        }
    }
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