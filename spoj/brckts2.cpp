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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

struct data
{
    ll w, h, childarea;
    data(): w(1), h(1), childarea(0) {}
};

void cp()
{
    string s;
    cin >> s;
    int n = ln(s);

    stack<data> st;
    st.push(data());
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            // add a child
            st.push(data());
        }
        else
        {
            // remove a child
            data me = st.top();
            st.pop();
            // calc parent
            st.top().w += me.w + 1;
            st.top().h = max(st.top().h, me.h + 1);
            st.top().childarea += me.w * me.h - me.childarea;
        }
    }
    data ans = st.top();
    cout << ans.childarea << endl;
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