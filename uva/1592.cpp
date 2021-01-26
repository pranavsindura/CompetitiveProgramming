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
const int MAXN = 1e4 + 5;

string arr[MAXN][11];

void cp()
{
    int n, m;
    while(cin >> n >> m)
    {
        cin.ignore();
        for(int i = 0; i < n; i++)
        {
            int idx = 0;
            string inp;
            getline(cin, inp);
            string temp;
            for(char x : inp)
                if(x == ',')
                    arr[i][idx] = temp, temp = "", idx++;
                else
                    temp += x;
            arr[i][idx] = temp;
        }
        bool found = false;
        vector<int> r, c;
        for(int i = 0; i < m && !found; i++)
        {
            for(int j = i + 1; j < m && !found; j++)
            {
                map<pair<string, string>, bool> cnt;
                pair<string, string> common;
                for(int k = 0; k < n && !found; k++)
                {
                    pair<string, string> me = {arr[k][i], arr[k][j]};
                    if(cnt.count(me))
                        found = true, common = me;
                    else
                        cnt[me] = true;
                }
                if(found)
                {
                    for(int k = 0; k < n && sz(r) < 2; k++)
                    {
                        pair<string, string> me = {arr[k][i], arr[k][j]};
                        if(me == common)
                            r.pb(k + 1);
                    }
                    c.pb(i + 1);
                    c.pb(j + 1);
                }
            }
        }
        if(found)
            cout << "NO\n" << r[0] << " " << r[1] << endl << c[0] << " " << c[1] << endl;
        else
            cout << "YES\n";
    }
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