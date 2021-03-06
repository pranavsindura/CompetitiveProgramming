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
    for(int &x : arr)
        cin >> x;
    bool sorted = true;
    for(int i = 1; i < n; i++)
        if(arr[i] < arr[i - 1])
            sorted = false;
    if(sorted)
    {
        cout << 0 << endl;
        return;
    }
    int group = 0;
    int cnt = 0;
    int l = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == i + 1)
            cnt++;
        else
        {
            if(cnt && l != 0)
                group++;
            cnt = 0;
            l = i + 1;
        }
    }
    if(group)
        cout << 2 << endl;
    else
        cout << 1 << endl;
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