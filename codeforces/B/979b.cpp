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

void cp()
{
    int turn;
    string a, b, c;
    cin >> turn >> a >> b >> c;
    int n = ln(a);
    // cout<<n<<endl;
    if(turn >= n)
    {
        cout << "Draw";
        return;
    }
    // Setting up a
    int t = turn;
    map<char, int> m;
    for(int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    char rep;
    int mx = -1;
    for(auto x : m)
    {
        if(x.ss > mx)
            mx = x.ss, rep = x.ff;
    }
    if(t + mx <= n)
    {
        for(int i = 0; i < n && t; i++)
        {
            if(a[i] != rep)
                a[i] = rep, t--;
        }
    }
    else
    {
        int rem = t + mx - n;
        a = string(n, rep);
        if(t == 1)
        {
            for(int i = 0; i < 26; i++)
            {
                if(a[0] != char(97 + i))
                {
                    a[0] = char(97 + i);
                    break;
                }
            }
        }
    }

    // Setting up b
    t = turn;
    m.clear();
    for(int i = 0; i < n; i++)
    {
        m[b[i]]++;
    }
    mx = -1;
    for(auto x : m)
    {
        if(x.ss > mx)
            mx = x.ss, rep = x.ff;
    }
    if(t + mx <= n)
    {
        for(int i = 0; i < n && t; i++)
        {
            if(b[i] != rep)
                b[i] = rep, t--;
        }
    }
    else
    {
        int rem = t + mx - n;
        b = string(n, rep);
        if(t == 1)
        {
            for(int i = 0; i < 26; i++)
            {
                if(b[0] != char(97 + i))
                {
                    b[0] = char(97 + i);
                    break;
                }
            }
        }
    }

    // Setting up c
    t = turn;
    m.clear();
    for(int i = 0; i < n; i++)
    {
        m[c[i]]++;
    }
    mx = -1;
    for(auto x : m)
    {
        if(x.ss > mx)
            mx = x.ss, rep = x.ff;
    }
    if(t + mx <= n)
    {
        for(int i = 0; i < n && t; i++)
        {
            if(c[i] != rep)
                c[i] = rep, t--;
        }
    }
    else
    {
        int rem = t + mx - n;
        c = string(n, rep);
        if(t == 1)
        {
            for(int i = 0; i < 26; i++)
            {
                if(c[0] != char(97 + i))
                {
                    c[0] = char(97 + i);
                    break;
                }
            }
        }
    }
    int cnt_a = -1, cnt_b = -1, cnt_c = -1;
    m.clear();
    for(int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    for(auto x : m)
    {
        cnt_a = max(cnt_a, x.ss);
    }

    m.clear();
    for(int i = 0; i < n; i++)
    {
        m[b[i]]++;
    }
    for(auto x : m)
    {
        cnt_b = max(cnt_b, x.ss);
    }

    m.clear();
    for(int i = 0; i < n; i++)
    {
        m[c[i]]++;
    }
    for(auto x : m)
    {
        cnt_c = max(cnt_c, x.ss);
    }
    mx = max({cnt_a, cnt_b, cnt_c});
    // cout << a << endl << b << endl << c << endl;
    if((cnt_a == mx && cnt_b == mx) || (cnt_a == mx && cnt_c == mx) || (cnt_b == mx && cnt_c == mx))
    {
        cout << "Draw";
    }
    else
    {

        if(cnt_a == mx)
            cout << "Kuro";
        else if(cnt_b == mx)
            cout << "Shiro";
        else
            cout << "Katie";
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