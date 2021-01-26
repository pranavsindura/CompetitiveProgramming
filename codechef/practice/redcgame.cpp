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

void cp()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    vector<int> arr;
    for(int i = 0, x; i < n; i++)
    {
        cin >> x;
        if(x > k)
            arr.pb(x - k);
        ans += min(x, k);
    }


    sort(all(arr));
    // We want to maximise the last element that is left
    // let us keep the last element intact
    // and reduce the n - 1 numbers
    // we also know that from the remaining numbers all of them will either become k
    // or 1 number will be left that needs to handled with the last intact number
    // if sum of first n-2 numbers is <= second last number, we can combine all n - 2 numbers with the second last number
    // or else the n-1 numbers will cancel each other out and last 0/1 depending on parity of their sum
    // as we can only reduce in pairs

    if(sz(arr) > 1)
    {
        int first_few = 0;
        for(int i = 0; i < sz(arr) - 2; i++)
            first_few += arr[i];
        int second_last = arr[sz(arr) - 2];
        int last = arr.back();

        if(first_few <= second_last)
        {
            second_last -= first_few;
            last -= second_last;
            ans += last;
        }
        else
            ans += last - ((first_few + second_last) & 1);
    }
    else if(sz(arr) == 1)
        ans += arr.front();

    cout << ans << endl;
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