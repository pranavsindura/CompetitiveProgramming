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

bool open(char s)
{
    return (s == '(' || s == '<' || s == '{' || s == '[');
}

bool closed(char s)
{
    return !open(s);
}

int type(char s)
{
    if(s == '(' || s == ')')
        return 0;
    else if(s == '{' || s == '}')
        return 1;
    else if(s == '<' || s == '>')
        return 2;
    else
        return 3;
}

void cp()
{
    string s;
    cin >> s;
    int n = ln(s);
    vector<int> ans(n);

    stack<pair<char, int>> st;

    for(int i = n - 1; i >= 0; i--)
    {
        if(closed(s[i]))
            st.push({s[i], i});
        else
        {
            // closing bracket to match it
            if(st.empty())
                continue;
            else
            {
                char x = st.top().ff;
                int last = st.top().ss;
                st.pop();

                if(type(x) == type(s[i]))  // can match
                {
                    ans[i] = ans[i + 1] + 2;
                    if(last + 1 < n)
                        ans[i] += ans[last + 1];
                }
                else
                {
                    // cannot match, also cannot match rest of the stack anymore either with any opening bracket
                    while(!st.empty())
                        st.pop();
                }
            }
        }
    }
    for(int x : ans)
        cout << x << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":\n";
        cp();
    }
    return 0;
}