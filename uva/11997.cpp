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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp(int n)
{
    vector<vector<int>> arr(n, vector<int>(n));
    for(auto &v : arr)
        for(int &x : v)
            cin >> x;
    if(n == 1)
    {
        cout << arr[0][0] << endl;
        return;
    }

    vector<int> small = arr[0];
    sort(all(small));
    for(int i = 1; i < n; i++)
    {
        sort(all(arr[i]));
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(int j = 0; j < n; j++)
            pq.push({small[j] + arr[i][0], 0});
        for(int j = 0; j < n; j++)
        {
            pi u = pq.top();
            pq.pop();
            small[j] = u.ff;
            if(u.ss + 1 < n)
                pq.push({small[j] - arr[i][u.ss] + arr[i][u.ss + 1], u.ss + 1});
        }
    }
    for(int i = 0; i < n; i++)
        cout << small[i] << " \n"[i == n - 1];
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> t)
    {
        cp(t);
    }
    return 0;
}