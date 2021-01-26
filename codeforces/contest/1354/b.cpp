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
    string s;
    cin >> s;
    int i = 0;
    int j = 0;
    int one = 0, two = 0, three = 0;
    int ans = INT_MAX;
    if(ln(s) < 3)
    {
        cout << 0 << endl;
        return;
    }
    if(s[i] == '1')
        one++;
    else if(s[i] == '2')
        two++;
    else
        three++;
    while(true)
    {
        if(one > 0 && two > 0 && three > 0)
        {

            if(s[i] == '1')
                one--;
            else if(s[i] == '2')
                two--;
            else
                three--;
            ans = min(ans, j - i + 1);
            i++;
            if(i == ln(s))
                break;
        }
        else
        {
            j++;
            if(j == ln(s))
                break;
            if(s[j] == '1')
                one++;
            else if(s[j] == '2')
                two++;
            else
                three++;
        }
    }
    if(ans == INT_MAX)
        ans = 0;
    cout << ans << endl;
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