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
    srand(time(NULL));
    int n = 50;
    int s = rand() % n + 1;
    int k = rand() % 2000 + 1;
    cout << n << " " << s << " " << k << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << rand() % 50 + 1 << " ";
    }
    cout << endl;
    string c = "RGB";
    for(int i = 0; i < n; i++)
        cout << c[rand() % 3];
    cout << endl;
    return 0;
}