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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    sort(all(arr));

    vector<int> temp = arr;
    vector<int> emp(n);

    int ans = 0;
    while(arr != emp && ~ans)
    {
        int num = arr.front();
        int distinct = 1;
        arr[0] = 0;

        for(int i = 1; i < n; i++)
        {
            if(arr[i] == num)
                arr[i] = 0;
            else
            {
                if(distinct < k)
                {
                    num = arr[i];
                    arr[i] = 0;
                    distinct++;
                }
                else
                    arr[i] -= num;
            }
        }
        ans++;
        if(arr == temp)
            ans = -1;
        else
            temp = arr;
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