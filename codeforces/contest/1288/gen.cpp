#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    srand(time_t(0));
    int t = rand()%100;
    cout<<t<<endl;

    while(t--)
    {
    	int n = rand()%100, d=rand()%100+n;
    	cout<<n<<" "<<d<<endl;
    }
    return 0;
}