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
const int MAXN = 1e5 + 5;

int arr[MAXN];
int dp[MAXN][2][2];
int n;
bool win(int i, bool turn, bool can_leave)
{
    if(i == n)
        return turn ^ 1;

    int &ret = dp[i][turn][can_leave];
    if(~ret)
    	return ret;

    // if arr[i] > 1 then we have 2 choices
    if(arr[i] > 1)
    {
        // if i can leave 1, then try
        // 1. leaving 1
        // 2. taking all
        bool who_won;
        if(can_leave)
        {
            bool c1 = win(i, turn ^ 1, false);
            bool c2 = win(i + 1, turn ^ 1, true);
            who_won = (c1 == turn || c2 == turn) ? turn : turn ^ 1;
        }
        // else simply take remaining and move on
        else
            who_won = win(i + 1, turn ^ 1, true);

        return ret = who_won;
    }
    else
        return ret = win(i + 1, turn ^ 1, true);
}

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = -1;

    bool winner = win(0, 0, 1);
    cout << (winner ? "Second\n" : "First\n");
}

// void cp()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int &x : arr)
//         cin >> x;
//     int one = 0;
//     for(int x : arr)
//         if(x == 1)
//             one++;
//     if(n == one)
//     {
//         if(n & 1)
//             cout << "First\n";
//         else
//             cout << "Second\n";
//     }
//     else
//     {
//         for(int i = 0; i < n; i++)
//         {
//             if(arr[i] > 1)
//             {
//                 if(i & 1)
//                     cout << "Second\n";
//                 else
//                     cout << "First\n";
//                 return;
//             }
//         }

//     }
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