#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vi arr(n + 1);
    arr[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    vi diff;
    int total = 0;
    int energy = 0;
    for(int i = 0; i < n; i++)
    {
        energy += arr[i] - arr[i + 1];
        if(energy < 0)
        {
        	total += abs(energy);
        	energy = 0;
        }
    }
    cout << total;
    return 0;
}