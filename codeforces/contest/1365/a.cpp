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
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    bool done = false;
    bool turn = true;
    while(!done)
    {
        done = true;
        bool placed = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                bool can = true;
                if(arr[i][j] == 0)
                {
                    for(int a = 0; a < n; a++)
                    {
                        if(arr[a][j])
                            can = false;
                    }
                    for(int a = 0; a < m; a++)
                    {
                        if(arr[i][a])
                            can = false;
                    }
                }
                else
                	continue;
                if(can)
                {
                    arr[i][j]  = 1;
                    turn = !turn;
                    done = false;
                    placed = true;
                    break;
                }
            }
            if(placed)
                break;
        }
    }
    if(turn)
        cout << "Vivek\n";
    else
        cout << "Ashish\n";
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