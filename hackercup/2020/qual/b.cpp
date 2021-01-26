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

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    stack<char> st;
    st.push(s[0]);
    st.push(s[1]);
    for(int i = 2; i < n; i++)
    {
        if(st.empty() || sz(st) <= 1)
            st.push(s[i]);
        else
        {
            char top = st.top();
            st.pop();
            char top2 = st.top();
            st.pop();
            if(top == top2 && top2 == s[i])
            {
                //all same just insert
                st.push(top2);
                st.push(top);
                st.push(s[i]);
            }
            else
            {
                if(top == top2 || top == s[i])
                    st.push(top);
                else
                    st.push(top2);
            }
        }
    }
    cout << (sz(st) == 1 ? "Y\n" : "N\n");
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}