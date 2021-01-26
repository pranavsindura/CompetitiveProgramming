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
    int arr[3][3];
    int r[3] = {0};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j], r[i] += arr[i][j];
    }
    for(int i = min({r[0], r[1], r[2]}); i <= 1e6; i++)
    {
        int a = i - r[0];
        int b = i - r[1];
        int c = i - r[2];
        if(a + b + c == i && a > 0 && b > 0 && c > 0 && a <= 1e5 && b <= 1e5 && c <= 1e5)
        {
            arr[0][0] = a;
            arr[1][1] = b;
            arr[2][2] = c;
            break;
        }
    }
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cout << arr[i][j] << " \n"[j == 2];
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