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

char get_diff(char a, char b)
{
    for(int i = 0; i < 26; i++)
    {
        if(char(97 + i) != a && char(97 + i) != b)
            return char(97 + i);
    }
}

void cp()
{
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;
    string ans(n, '*');
    bool ok = false;
    int same = 0;
    int diff = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] != t[i])
            diff++;
        else
            same++;
    }
    int one, two;
    for(int i = 0; i <= k; i++)
    {
    	//get i difference with 2 characters
    	//get k-i difference with 1 character
        if(2 * i <= diff && 2 * i + (k - i) >= diff && 2 * i + (k - i) <= n)
        {
            ok = true;
            one = k - i;
            two = i;
            break;
        }
    }
    if(!ok)
    {
        cout << -1;
        return;
    }
    int i;
    two *= 2;
    bool change = false;
    //fix two characters alternating
    for(i = 0; i < n; i++)
    {
        if(s[i] != t[i])
        {
            if(two)
            {
                if(change)
                    ans[i] = t[i];
                else
                    ans[i] = s[i];
                two--;
                change = !change;
            }
        }
    }
    //fix one character with different ones first
    for(i = 0; i < n; i++)
    {
        if(s[i] != t[i])
        {
            if(ans[i] == '*')
            {
                if(one)
                    ans[i] = get_diff(s[i], t[i]), one--;
            }
        }
    }
    //fix one character with same characters now
    for(i = 0; i < n; i++)
    {
        if(s[i] == t[i])
        {
            if(ans[i] == '*')
            {
                if(one)
                    ans[i] = get_diff(s[i], t[i]), one--;
            }
        }
    }
    for(i = 0; i < n; i++)
    {

        if(ans[i] == '*')
            ans[i] = s[i];
    }
    cout << ans;
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