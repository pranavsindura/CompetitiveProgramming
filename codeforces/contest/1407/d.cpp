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
const int MAXN = 3e5 + 5;

int arr[MAXN], dist[MAXN];
int prev_more[MAXN], prev_less[MAXN];
int next_more[MAXN], next_less[MAXN];

void cp()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> st;

    // Previous larger element
    clr(prev_more, -1);
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if(!st.empty())
            prev_more[i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();

    // Previous smaller element
    clr(prev_less, -1);
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if(!st.empty())
            prev_less[i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();

    // Next larger element
    clr(next_more, -1);
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if(!st.empty())
            next_more[i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();

    // Next smaller element
    clr(next_less, -1);
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if(!st.empty())
            next_less[i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++)
    {
        if(~prev_less[i])
            adj[prev_less[i]].pb(i);
        if(~prev_more[i])
            adj[prev_more[i]].pb(i);
        if(~next_less[i])
            adj[i].pb(next_less[i]);
        if(~next_more[i])
            adj[i].pb(next_more[i]);
    }

    fill(dist, dist + n, (int)1e7);
    dist[0] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    while(!pq.empty())
    {
        pi node = pq.top();
        pq.pop();
        int u = node.ss;
        int d = node.ff;
        if(dist[u] < d)
            continue;
        for(int v : adj[u])
        {
            if(dist[u] + 1 < dist[v])
            {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << dist[n - 1] << endl;
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