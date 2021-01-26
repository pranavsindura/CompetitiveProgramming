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

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    int first_c = -1, last_t = -1, first_a = -1, last_a = -1;
    for(int i = n - 1; i >= 0; i--)
        if(s[i] == 'c')
            first_c = i;
    for(int i = 0; i < n; i++)
        if(s[i] == 't')
            last_t = i;

    if(~first_c && ~last_t &&first_c <= last_t)
    {
        for(int i = last_t; i >= first_c; i--)
            if(s[i] == 'a')
                first_a = i;

        for(int i = first_c; i <= last_t; i++)
            if(s[i] == 'a')
                last_a = i;

        if(~first_a)
        {
            int cc = 0, ca = 0, ct = 0;

            for(int i = first_c; i <= first_a; i++)
                cc += (s[i] == 'c');
            for(int i = first_a; i <= last_a; i++)
                ca += (s[i] == 'a');
            for(int i = last_a; i <= last_t; i++)
                ct += (s[i] == 't');
            int best = min({cc, ca, ct});
            char ignore;
            if(best == cc)
                ignore = 'c';
            else if(best == ca)
                ignore = 'a';
            else
                ignore = 't';
            string ans;
            for(int i = 0; i < first_c; i++)
                ans += s[i];
            for(int i = first_c; i <= last_t; i++)
                if(s[i] != ignore)
                    ans += s[i];
            for(int i = last_t + 1; i < n; i++)
                ans += s[i];
            cout << ln(ans) << endl << ans << endl;
        }
        else
            cout << n << endl << s << endl;
    }
    else
        cout << n << endl << s << endl;
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