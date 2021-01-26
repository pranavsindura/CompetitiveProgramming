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

void cp()
{
    int n, k;
    cin >> n >> k;
    int arr[n][n];
    clr(arr, 0);

    int r = 0, c = 0;
    int c_off = 0;
    
    while(k--)
    {
        arr[r][(c + c_off) % n] = 1;
        r++, c++;
        if(r == n)
            r %= n, c_off++;
        c %= n;
    }

    vector<int> row(n, 0), col(n, 0);
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            cnt += arr[i][j];
        }
        row[i] = cnt;
    }
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            cnt += arr[j][i];
        }
        col[i] = cnt;
    }
    int row_sum = *max_element(all(row)) - *min_element(all(row));
    row_sum *= row_sum;
    int col_sum = *max_element(all(col)) - *min_element(all(col));
    col_sum *= col_sum;

    cout << row_sum + col_sum << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
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