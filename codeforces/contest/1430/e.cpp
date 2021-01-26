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

vector<int> arr;
ll merge(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    ll inv_count = 0;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k] = L[i], i++;
        else
            arr[k] = R[j], j++, inv_count += n1 - i;
        k++;
    }
    while(i < n1)
        arr[k] = L[i], i++, k++;
    while(j < n2)
        arr[k] = R[j], j++, k++;
    return inv_count;
}

ll mergeSort(int l, int r)
{
    if(l >= r)
        return 0;
    int m = (l + r) / 2;
    ll left = mergeSort(l, m);
    ll right = mergeSort(m + 1, r);
    ll mid = merge(l, m, r);
    return left + right + mid;
}

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> pos(26);
    arr.resize(n);

    for(int i = 0; i < n; i++)
        pos[s[i] - 'a'].pb(i);

    for(int i = 0; i < 26; i++)
        reverse(all(pos[i]));

    for(int i = 0; i < n; i++)
    {
        int need = s[n - i - 1] - 'a';
        int idx = pos[need].back();
        pos[need].pop_back();
        arr[idx] = i;
    }

    cout << mergeSort(0, n - 1) << endl;
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