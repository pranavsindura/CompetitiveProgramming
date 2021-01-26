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

void get_digits(int num, vector<int> &rep)
{
    for(int i = 0; i < 4; i++)
    {
        int m = num % 10;
        rep.pb(m);
        num = num / 10;
    }
    reverse(all(rep));
}

void pr(vector<int> &dig)
{
    for(int p : dig)
        cout << p;
    cout << endl;
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> nums;
    vector<pi> bull_cow;
    for(int i = 0; i < n; i++)
    {
        int num, bull, cow;
        cin >> num >> bull >> cow;
        vector<int> digits;
        get_digits(num, digits);
        nums.pb(digits);
        bull_cow.pb({bull, cow});
    }
    vector<int> possible;
    for(int num = 0; num < 10000; num++)
    {
        vector<int> digits;
        get_digits(num, digits);
        set<int> s(all(digits));
        if(sz(s) < 4)
            continue;
        bool ok = true;
        for(int j = 0; j < n; j++)
        {
            int bull = 0, cow = 0;
            for(int a = 0; a < 4; a++)
            {
                for(int b = 0; b < 4; b++)
                {
                    if(digits[a] == nums[j][b])
                    {
                        if(a == b)
                            bull++;
                        else
                            cow++;
                    }
                }
            }
            if(pi{bull, cow} != bull_cow[j])
            {
                ok = false;
                break;
            }
        }
        if(ok)
            possible.pb(num);
    }
    if(sz(possible) == 1)
    {
        vector<int> digits;
        get_digits(possible.back(), digits);
        pr(digits);
    }
    else if(possible.empty())
    {
        cout << "Incorrect data";
    }
    else
    {
        cout << "Need more data";
    }
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