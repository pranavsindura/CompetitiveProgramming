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
int n, m;
int arr[505][505];

vector<int> cons(505);

void f(int i)
{
    int ans = INT_MIN;
    int a = 0;
    for(int j = 0; j < m; j++)
    {
        if(arr[i][j] == 0)
            a = 0;
        else
            a = a + 1;
        ans = max(ans, a);
    }
    cons[i] = ans;
}

int main()
{
    FASTIO;
    int q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        f(i);
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        arr[a][b] = arr[a][b] ? 0 : 1;
        f(a);
        cout << *max_element(cons.begin(), cons.begin() + n) << endl;
    }
    return 0;
}