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

// DP

int n, s, k;
vector<int> arr;
string colour;

int dp[55][1305];

int solve(int i, int candies)
{
    if(i == n)
        return (candies >= k ? 0 : 3000);

    int &ret = dp[i][candies];
    if(~ret)
        return ret;

    int ans = 3000;

    if(candies >= k)
        ans = 0;

    for(int j = 0; j < n; j++)
        if(arr[j] > arr[i] && colour[j] != colour[i])
            ans = min(ans, abs(i - j) + solve(j, candies + arr[j]));

    return ret = ans;
}

void cp()
{
    cin >> n >> s >> k;
    arr.resize(n);
    for(int &x : arr)
        cin >> x;
    cin >> colour;

    clr(dp, -1);

    int ans = 3000;
    for(int i = 0; i < n; i++)
        ans = min(ans, abs(s - 1 - i) + solve(i, arr[i]));

    if(ans >= 3000)
        ans = -1;
    
    cout << ans << endl;
}


// GREEDY - DIJKSTRA

// struct node
// {
//     int t, candies, prevcolour, preveaten, pos;
//     node() {}
//     node(int t, int candies, int prevcolour, int preveaten, int pos): t(t), candies(candies),
//         prevcolour(prevcolour), pos(pos), preveaten(preveaten) {}
//     const bool operator<(const node &nd) const
//     {
//         if(t == nd.t)
//             return candies < nd.candies;
//         else
//             return t > nd.t;
//     }
// };

// bool vis[1300][55][1300];

/*
	Trying not to repeat the same (candies, position, time) triplet
	At max we need to collect all nodes and for that case they must be 1,2,3,4,5...50
	the max candies we can accumulate is 50*51/2 = 1275
	Now we will achieve max time when the separations are maximum, 1 is leftmost, 2 is rightmost
	3 comes after 1, 4 comes before 2 and so on
	1 3 5 ... 6 4 2
	For that case the time taken will be n-1+n-2+n-3+... = n*(n-1)/2 = 49*50/2 = 1225

*/

// void cp()
// {
//     int n, s, k;
//     string colour;
//     cin >> n >> s >> k;
//     vector<int> arr(n);
//     for(int &x : arr)
//         cin >> x;
//     cin >> colour;

//     vector<vector<int>> adj(n);
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             if(arr[j] > arr[i] && colour[j] != colour[i])
//                 adj[i].pb(j);

//     ll ans = -1;

//     priority_queue<node> pq;
//     for(int i = 0; i < n; i++)
//         // eat this candy and start from here
//         pq.push(node(abs(i - (s - 1)), arr[i], colour[i], arr[i], i));

//     while(!pq.empty())
//     {
//         node u = pq.top();
//         pq.pop();
//         vis[u.candies][u.pos][u.t] = 1;

//         if(u.candies >= k)
//         {
//             ans = u.t;
//             break;
//         }

//         for(int i : adj[u.pos])
//         {
//             node v = u;
//             // eat that candy
//             v.candies += arr[i];
//             v.preveaten = arr[i];
//             v.prevcolour = colour[i];
//             // stand there
//             v.t += abs(i - u.pos);
//             v.pos = i;
//             if(v.candies < 1300 && !vis[v.candies][v.pos][v.t]) // TLEs without this
//                 pq.push(v), vis[v.candies][v.pos][v.t] = 1;
//         }
//     }
//     cout << ans << endl;
// }

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