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

int conv(char a, char b)
{
    int mi = min(a, b);
    int mx = max(a, b);

    int c1 = mx - mi;
    int c2 = (mi - mx + 26) % 26;
    return min(c1, c2);
}

void cp()
{
    int n, p;
    string s;
    cin >> n >> p >> s;
    p--;
    vector<int> process;
    for(int i = 0; i < (n + 1) / 2; i++)
    {
        if(s[i] != s[n - i - 1])
        {
            if(side)
                process.pb(i);
            else
                process.pb(n - i - 1);
        }
    }
    vector<int> left, right;
    for(int x : process)
    {
        if(x <= p)
            left.pb(x);
        else
            right.pb(x);
    }
    sort(all(right));
    sort(all(left));
    int cost1 = 0;
    int cost_left = 0, cost_right = 0;
    // go left , go right, add min of two costs because of overlap either from left or right
    for(int i = sz(left) - 1; i >= 0; i--)
    {
        if(i == sz(left) - 1)
            cost1 += abs(p - left[i]), cost_left += abs(p - left[i]);
        else
            cost1 += abs(left[i] - left[i + 1]), cost_left += abs(left[i] - left[i + 1]);
        cost1 += conv(s[left[i]], s[n - left[i] - 1]);
    }
    for(int i = 0; i < sz(right); i++)
    {
        if(i == 0)
            cost1 += abs(p - right[i]), cost_right += abs(p - right[i]);
        else
            cost1 += abs(right[i - 1] - right[i]), cost_right += abs(right[i - 1] - right[i]);
        cost1 += conv(s[right[i]], s[n - right[i] - 1]);
    }
    cost1 += min(cost_right, cost_left);
    cout << cost1;
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