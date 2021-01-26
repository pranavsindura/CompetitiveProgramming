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

int arr[105][105], hist[105][105];
int n;

void cp()
{
    int m;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = 1, hist[i][j] = 0;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        for(int a = r1; a <= r2; a++)
            for(int b = c1; b <= c2; b++)
                arr[a][b] = 0;
    }

    for(int j = 0; j < n; j++)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i][j])
                cnt++;
            else
                cnt = 0;
            hist[i][j] = cnt;
        }
    }
    // Forcing last to finish
    for(int i = 0; i < n; i++)
        hist[i][n] = -1;

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        stack<pi> st;
        for(int j = 0; j <= n; j++)
        {
            pi me = {j, hist[i][j]};
            ans = max(ans, me.ss);
            while(!st.empty() && st.top().ss > me.ss)
            {
                ans = max(ans, (j - st.top().ff) * st.top().ss);
                me.ff = st.top().ff;
                st.pop();
            }
            st.push(me);
        }
    }
    cout << ans << endl;
}

// void cp()
// {
//     int m;
//     cin >> n;
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             arr[i][j] = 1;
//     cin >> m;
//     for(int i = 0; i < m; i++)
//     {
//         int r1, c1, r2, c2;
//         cin >> r1 >> c1 >> r2 >> c2;
//         r1--, c1--, r2--, c2--;
//         for(int a = r1; a <= r2; a++)
//             for(int b = c1; b <= c2; b++)
//                 arr[a][b] = 0;
//     }
//     for(int i = 0; i < n; i++)
//         for(int j = 1; j < n; j++)
//             arr[i][j] += arr[i][j - 1];

//     int ans = 0;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = i; j < n; j++)
//         {
//             //[i, j] col window
//             int need = j - i + 1;
//             // find most rows with consecutive need sum
//             int cnt = 0;
//             for(int k = 0; k < n; k++)
//             {
//                 int sum = arr[k][j] - (i ? arr[k][i - 1] : 0);
//                 if(sum == need)
//                     cnt++;
//                 else
//                     cnt = 0;
//                 ans = max(ans, cnt * need);
//             }
//         }
//     }
//     cout << ans << endl;
// }

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