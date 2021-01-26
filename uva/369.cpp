#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

ll arr[101][101];

void init()
{
    arr[1][0] = 1;
    arr[1][1] = 1;
    for(int i = 2; i <= 100; i++) {
        arr[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]);
        }
        arr[i][i] = 1;
    }
}

int main()
{
    init();
    FASTIO;
    ll n,m;
    cin>>n>>m;
    while(n && m)
    {
        cout<<n<<" things taken "<<m<<" at a time is "<<arr[n][m]<<" exactly."<<endl;
        cin>>n>>m;
    }
    return 0;
}