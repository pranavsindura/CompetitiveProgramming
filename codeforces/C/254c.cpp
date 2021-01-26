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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, t;
    cin >> s >> t;
    int n = ln(s);
    int op = 0;
    map<char, int> ms, mt;
    for(char x : s)
        ms[x]++;
    for(char x : t)
        mt[x]++;
    string place;
    for(char c = 'A'; c <= 'Z'; c++)
    {
        if(ms[c] <= mt[c])
        {
            int need = mt[c] - ms[c];
            op += need;
            for(int i = 0; i < need; i++)
                place += c;
        }
    }

    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        if(ms[s[i]] > mt[s[i]])
        {
            if(place[pos] < s[i] || mt[s[i]] == 0)
            {
                ms[s[i]]--;
                ms[place[pos]]++;
                s[i] = place[pos];
                pos++;
            }
            else
            {
                ms[s[i]]--;
                mt[s[i]]--;
            }
        }
    }

    cout << op << endl << s;
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