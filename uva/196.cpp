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

int arr[1005][1005];

vector<pii> getposarr(string s)
{
    for(char &x : s)
    {
        if(x == '+' || x == '=')
            x = ' ';
    }
    stringstream ss(s);
    vector<pii> v;
    string temp;
    while(!ss.eof())
    {
        ss >> temp;
        int j;
        int col = 0, row = 0;
        for(int i = 0; i < ln(temp); i++)
        {
            if(temp[i] <= '9' && temp[i] >= '0')
            {
                j = i;
                break;
            }
            col *= 26;
            col += temp[i] - 'A' + 1;
        }
        for(int i = j; i < ln(temp); i++)
        {
            row *= 10;
            row += temp[i] - '0';
        }
        row--;
        col--;
        v.pb(mp(row, col));
    }
    return v;
}

int solve(int x, int y, map<pii, vector<pii>> &calc)
{
    if(arr[x][y] != -1)
        return arr[x][y];
    int &ret = arr[x][y];
    ret = 0;
    for(pii a : calc[mp(x, y)])
    {
        ret += solve(a.ff, a.ss, calc);
    }
    return ret;
}

int conv(string s)
{
    int ans = 0;
    for(char x : s)
    {
        ans *= 10;
        ans += x - '0';
    }
    return ans;
}

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> m >> n;
        map<pii, vector<pii>> calc;
        string s;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> s;
                if(s[0] == '=')
                {
                    calc[mp(i, j)] = getposarr(s);
                    arr[i][j] = -1;
                }
                else
                    arr[i][j] = conv(s);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == -1)
                    solve(i, j, calc);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(j == m - 1)
                    cout << arr[i][j];
                else
                    cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}