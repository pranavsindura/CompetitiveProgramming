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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

int prec(char c)
{
    if(c == '(' || c == ')')
        return 2;
    else if(c == '*' || c == '/')
        return 1;
    else
        return 0;
}

void cp()
{
    string s;
    string ans;
    stack<char> st;
    while(getline(cin, s) && !s.empty())
    {
        char c = s[0];
        if(isdigit(c))
            ans += c;
        else
        {
            if(c == '(')
                st.push(c);
            else if(c == ')')
            {
                while(!st.empty() && st.top() != '(')
                    ans += st.top(), st.pop();
                st.pop();
            }
            else
            {
                while(!st.empty() && prec(st.top()) >= prec(c) && st.top() != '(')
                    ans += st.top(), st.pop();
                st.push(c);
            }
        }
    }
    while(!st.empty())
        ans += st.top(), st.pop();
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--)
    {
        cp();
        if(t)
            cout << endl;
    }
    return 0;
}