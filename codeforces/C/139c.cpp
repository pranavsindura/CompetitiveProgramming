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

string extract(string s, int k)
{
    string ans;
    reverse(all(s));
    bool found = false;
    int cnt = 0;

    for(char x : s)
    {
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            cnt++;
        ans += x;
        if(cnt == k)
        {
            found = true;
            break;
        }
    }

    if(found)
        return ans;
    else
        return "";
}

void cp()
{
    int n, k;
    cin >> n >> k;
    bool ok = true;
    map<string, int> scheme;
    for(int i = 0; i < n; i++)
    {
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        a = extract(a, k);
        b = extract(b, k);
        c = extract(c, k);
        d = extract(d, k);

        if(a.empty() || b.empty() || c.empty() || d.empty())
            ok = false;

        if(a == b && b == c && c == d)
            scheme["aaaa"]++;
        else if(a == b && c == d)
            scheme["aabb"]++;
        else if(a == c && b == d)
            scheme["abab"]++;
        else if(a == d && b == c)
            scheme["abba"]++;
        else
            ok = false;
    }

    if(ok)
    {
        if(scheme.empty())
            cout << "NO";
        else if(sz(scheme) == 1)
            cout << begin(scheme)->ff;
        else if(sz(scheme) == 2)
        {
            scheme.erase("aaaa");
            if(sz(scheme) == 2)
                cout << "NO";
            else
                cout << begin(scheme)->ff;
        }
        else
            cout << "NO";
    }
    else
        cout << "NO";
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