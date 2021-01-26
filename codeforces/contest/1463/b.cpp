#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

/*
	we know that we can place 1 in between 2 numbers and that will fulfill our
	purpose
	a 1 b 1 c .. is valid as the divisibility is satisfied

	Also any way you pick half of the numbers
	one of the two halves will have sum >= S/2

	So we can choose to place 1s at all odd or even positions
	whichever has lower sum, that will keep our total difference <= S/2
*/

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    int rem = 0;
    ll odd = 0, even = 0;
    for(int i = 0; i < n; i++)
        if(i & 1) odd += arr[i];
        else even += arr[i];

    if(odd > even) rem = 0;
    else rem = 1;
    
    for(int i = 0; i < n; i++)
        if(i % 2 == rem) arr[i] = 1;

    for(int x : arr)
        cout << x << " ";
    cout << endl;
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

