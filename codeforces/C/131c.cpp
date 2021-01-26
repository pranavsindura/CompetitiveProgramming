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

ll ncr[35][35];

void init()
{
    for(int i = 1; i < 35; i++)
    {
        for(int j = 0; j < 35; j++)
        {
            //i C j
            if(j == 0 || i == j)
                ncr[i][j] = 1;
            else
                ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
}

int main()
{
    FASTIO;
    init();
    int n, m, t;
    cin >> n >> m >> t;
    ll ans = 0;
    for(int i=4;i<t;i++)
    {
    	int boy = i, girl = t-i;
    	if(boy > n || girl > m)
    		continue;
    	ans += ncr[n][boy]*ncr[m][girl];
    }
    cout<<ans;
    return 0;
}