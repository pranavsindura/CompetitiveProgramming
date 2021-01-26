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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;
int ty(char x)
{
    if(x == '(')
        return 1;
    else if(x == ')')
        return -1;
    else if(x == '{')
        return 2;
    else if(x == '}')
        return -2;
    else if(x == '<')
        return 3;
    else if(x == '>')
        return -3;
    else if(x == '[')
        return 4;
    else if(x == ']')
        return -4;

}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++)
    {
        string s;
        cin >> s;
        int d = 0;
        int prev = 0;
        vector<int> ans(ln(s), 0);
        cout << "Case " << test_case << ":" << endl;
        for(int i = ln(s) - 1; i >= 0; i--)
        {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']' || s[i] == '>')
                continue;
            int ind = i + 1;
            int cnt = 0;
            if(ind >= ln(s))
                continue;
            if(ans[ind] != 0)
                cnt += ans[ind], ind += ans[ind];
            if(ind >= ln(s))
                continue;
            if( ty(s[i]) + ty(s[ind]) != 0)
                continue;

            ans[i] = cnt + 2;
            if(ind + 1 >= ln(s))
                continue;
            ans[i] += ans[ind + 1];

        }
        for(int x : ans)
            cout << x << endl;
    }
    return 0;
}