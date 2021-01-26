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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int arr[80][80];
int pref[80], suff[80];
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            arr[i][j] += arr[i][j - 1];

    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int sofar = 0, total = 0;
            for(int k = 0; k < n; k++)
            {
                int sum = 0;
                if(i <= j)
                    sum = arr[k][j] - (i ? arr[k][i - 1] : 0);
                else
                    sum = arr[k][n - 1] - (i ? arr[k][i - 1] : 0) + arr[k][j];

                sofar = max(sofar + sum, sum);
                total += sum;
                ans = max(ans, sofar);
                pref[k] = total;
            }
            for(int k = 1; k < n; k++)
                pref[k] = max(pref[k], pref[k - 1]);

            sofar = 0, total = 0;
            for(int k = n - 1; k >= 0; k--)
            {
                int sum = 0;
                if(i <= j)
                    sum = arr[k][j] - (i ? arr[k][i - 1] : 0);
                else
                    sum = arr[k][n - 1] - (i ? arr[k][i - 1] : 0) + arr[k][j];

                sofar = max(sofar + sum, sum);
                total += sum;
                ans = max(ans, sofar);
                suff[k] = total;
            }
            for(int k = n - 2; k >= 0; k--)
                suff[k] = max(suff[k + 1], suff[k]);

            for(int k = 0; k < n - 1; k++)
                ans = max(ans, pref[k] + suff[k + 1]);
        }
    }
    cout << ans << endl;
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