#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    string s, t;
    cin >> s >> t;
    if(ln(s) < ln(t))
    {
        cout << 0;
        return;
    }
    int hs[26] = {0}, ht[26] = {0};
    int ques = 0;
    for(char x : t)
        ht[x - 'a']++;
    for(int i = 0; i < ln(t); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            hs[s[i] - 'a']++;
        else
            ques++;
    }
    int i = ln(t) - 1;
    int count = 0;
    while(true)
    {
        int rem = 0;
        for(int c = 0; c < 26; c++)
        {
            if(hs[c] < ht[c])
                rem += ht[c] - hs[c];
        }
        if(ques >= rem)
            count++;
        //i-ln(t)+1 is left end
        if(s[i - ln(t) + 1] == '?')
            ques--;
        else
            hs[s[i - ln(t) + 1] - 'a']--;
        i++;
        if(i < ln(s))
        {
            if(s[i] == '?')
                ques++;
            else
                hs[s[i] - 'a']++;
        }
        else
            break;
    }
    cout << count;
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