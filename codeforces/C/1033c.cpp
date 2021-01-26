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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++)
        cin >> arr[i], pos[arr[i]] = i;
    vector<int> win(n);
    for(int num = n; num > 0; num--)
    {
        int i = pos[num];
        win[i] = 2;
        for(int offset = arr[i]; offset <= n; offset += arr[i])
        {
            int left = i - offset;
            int right = i + offset;
            if(left >= 0 && arr[left] > arr[i] && win[left] == 2)
                win[i] = 1;
            if(right < n && arr[right] > arr[i] && win[right] == 2)
                win[i] = 1;
        }
    }
    for(int x : win)
        cout << (x == 1 ? 'A' : 'B');
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