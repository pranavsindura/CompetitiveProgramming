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
const int MAXN = 1e5 + 5;

int out[MAXN];
int cost = 0;
void pop(int x)
{
    if(out[x] == 0)
        return;
    else
    {
        cost++;
        pop(out[x]);
        out[x] = 0;
    }
}

void cp()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int m;
        cin >> m;
        vector<int> arr(m);
        for(int j = 0; j < m; j++)
        {
            cin >> arr[j];
        }
        for(int j = 0; j < m - 1; j++)
        {
            out[arr[j]] = arr[j + 1];
        }
        out[arr[m - 1]] = 0;
    }

    for(int i = 1; i < n; i++)
    {
        if(out[i] == i + 1)
        {
            //ok
        }
        else
        {
            pop(i);
            pop(i + 1);
            out[i] = i + 1;
            cost++;
        }
    }
    cout << cost;
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