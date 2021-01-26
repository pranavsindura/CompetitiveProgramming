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
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    int n, m, c = 0;
    cin >> n >> m;
    char arr[n][m];
    string col = "BW";
    bool flip = false;
    for(int i = 0; i < n; i++)
    {
        if(flip)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                arr[i][j] = col[c];
                c ^= 1;
            }
        }
        else
        {
            for(int j = 0; j < m; j++)
            {
                arr[i][j] = col[c];
                c ^= 1;
            }
        }
        if(m % 2 == 0)
            flip = !flip;

    }
    if((n * m) % 2 == 0)
    {
        arr[0][1] = 'B';
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
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