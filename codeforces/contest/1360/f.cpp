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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 11;
vector<string> arr(MAXN);
int n, m;

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    string ans = arr[0];
    for(int j = 0; j < m; j++)
    {
        char temp = ans[j];
        for(int c = 'a'; c <= 'z'; c++)
        {
            ans[j] = c;
            bool found = true;
            for(int i = 0; i < n; i++)
            {
                int diff = 0;
                for(int k = 0; k < m; k++)
                {
                    if(arr[i][k] != ans[k])
                    {
                        diff++;
                    }
                }
                if(diff > 1)
                {
                    found = false;
                }
            }
            if(found)
            {
                cout << ans << endl;
                return;
            }
        }
        ans[j] = temp;
    }
    cout << -1 << endl;
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