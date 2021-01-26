#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int a, b, a1, b1, a2, b2;
    cin >> a >> b >> a1 >> b1 >> a2 >> b2;
    bool ok = false;
    if(b1 + a2 <= b && max(a1, b2) <= a)
        ok = true;
    else if(b1 + b2 <= b && max(a1, a2) <= a)
        ok = true;
    else if(a1 + b2 <= b && max(b1, a2) <= a)
        ok = true;
    else if(a1 + a2 <= b && max(b1, b2) <= a)
        ok = true;
    swap(a, b);
    if(b1 + a2 <= b && max(a1, b2) <= a)
        ok = true;
    else if(b1 + b2 <= b && max(a1, a2) <= a)
        ok = true;
    else if(a1 + b2 <= b && max(b1, a2) <= a)
        ok = true;
    else if(a1 + a2 <= b && max(b1, b2) <= a)
        ok = true;
    cout << (ok ? "YES" : "NO");
    return 0;
}