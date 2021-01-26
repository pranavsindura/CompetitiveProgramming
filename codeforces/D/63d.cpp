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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char grid[150][150];
bool vis[150][150];
void cp()
{
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int pos = 0;
    char marker = 'a';
    int cnt[26] = {0};


    for(int i = 1; i <= max(b, d); i++)
        for(int j = 1; j <= a + c; j++)
            grid[i][j] = '.';

    int i, j, dir;
    if(a & 1)
        i = b, j = 1, dir = -1;
    else
        i = 1, j = 1, dir = 1;
    int count = 0;
    while(count < a * b + c * d)
    {
        count++;
        grid[i][j] = marker;
        cnt[pos]++;
        if(cnt[pos] == arr[pos])
            pos++, marker++;
        i = i + dir;
        if(j <= a)
        {
            // we are in a * b
            if(i > b)
            {
                i = b;
                j++;
                dir = -1;
            }
            else if(i < 1)
            {
                i = 1;
                j++;
                dir = 1;
            }
        }
        else
        {
            // we are in c * d
            if(i > d)
            {
                i = d;
                j++;
                dir = -1;
            }
            else if(i < 1)
            {
                i = 1;
                j++;
                dir = 1;
            }
        }
    }

    cout << "YES\n";
    for(int i = 1; i <= max(b, d); i++)
    {
        for(int j = 1; j <= a + c; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
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