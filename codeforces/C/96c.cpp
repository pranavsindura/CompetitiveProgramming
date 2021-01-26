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
    cin >> n;
    string s;
    char rep;
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;
    cin >> s >> rep;
    vector<bool> should(sz(s), false);
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i + sz(arr[k]) - 1 < sz(s); i++)
        {
            bool match = true;
            for(int j = 0; j < sz(arr[k]); j++)
            {
                if(tolower(s[i + j]) != tolower(arr[k][j]))
                    match = false;
            }

            if(match)
                for(int j = 0; j < sz(arr[k]); j++)
                    should[i + j] = true;
        }
    }

    for(int i = 0; i < sz(should); i++)
    {
        if(!should[i])
            continue;
        if(tolower(s[i]) == tolower(rep))
        {
            if(tolower(s[i]) != 'a')
            {
                if(isupper(s[i]))
                    s[i] = 'A';
                else
                    s[i] = 'a';
            }
            else
            {
            	if(isupper(s[i]))
                    s[i] = 'B';
                else
                    s[i] = 'b';
            }
        }
        else
        {
            if(isupper(s[i]))
                s[i] = toupper(rep);
            else
                s[i] = tolower(rep);
        }
    }
    cout << s;
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