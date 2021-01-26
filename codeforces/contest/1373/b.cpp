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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
void cp()
{
    string s;
    cin >> s;
    int moves = 0;
    stack<char> st;
    for(int i = 0; i < ln(s); i++)
    {
        if(st.empty())
            st.push(s[i]);
        else
        {
            if(st.top() != s[i])
            {
                st.pop();
                moves++;
                //dont put char
            }
            else
                st.push(s[i]);
        }
    }
    if(moves & 1)
        cout << "DA\n";
    else
        cout << "NET\n";
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