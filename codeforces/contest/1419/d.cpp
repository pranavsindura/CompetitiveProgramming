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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    if(n > 2)
    {
        sort(all(arr));
        bool turn = 1;
        int i = (n - 1) / 2 - 1, j = n - 1;
        vector<int> temp;
        int cnt = 0;
        int tot = 0;
        while(tot < n)
        {
            if(turn)
                temp.pb(arr[j]), j--, tot++;
            else
            {
                if(i >= 0)
                    temp.pb(arr[i]), i--;
                else
                    temp.pb(arr[j]), j--;
                tot++;
            }
            turn ^= 1;
        }
        for(i = 1; i < n - 1; i++)
            if(temp[i - 1] > temp[i] && temp[i] < temp[i + 1])
                cnt++;
        cout << cnt << endl;
        for(int x : temp)
            cout << x << " ";

    }
    else
    {
        cout << 0 << endl;
        for(int x : arr)
            cout << x << " ";

    }
    cout << endl;
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