#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

void cp()
{
    string s;
    cin >> s;

    string temp;
    int cnt = 0;
    for(int x : s)
    {
        if(!temp.empty() && temp.back() == x)
        {
            cnt++;
            if(cnt == 3)
                cnt--;
            else
                temp += x;
        }
        else
            temp += x, cnt = 1;
    }

    cnt = 0;
    string ans(1, temp[0]);
    bool first = true;
    for(int i = 1; i < ln(temp); i++)
    {
        if(ans.back() == temp[i])
        {
            if(first)
                ans += temp[i], first = false;
            else
                first = true;
            cnt = 0;
        }
        else
            ans += temp[i], cnt++;
        if(cnt > 1)
        	first = true;
    }

    cout << ans << endl;
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