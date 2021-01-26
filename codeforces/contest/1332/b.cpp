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
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

set<int> pf(int x)
{
    set<int> res;
    if(x % 2 == 0)
    {
        while(x % 2 == 0)
            x /= 2;
        res.insert(2);
    }
    for(int i = 3; i * i <= x; i += 2)
    {
        if(x % i == 0)
        {
            while(x % i == 0)
                x /= i;
            res.insert(x);
        }
    }
    if(x > 1)
        res.insert(x);
    return res;
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    set<int> temp(all(arr));
    vector<vector<int>> v(170);
    vector<set<int>> g(12);
    int m = 0;
    for(int i = 0; i < sz(prime); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!arr[j])
                continue;
            if(arr[j] % prime[i] == 0)
            {
                if(!sz(v[i]))
                    m++;
                v[i].pb(j);
                arr[j] = 0;
            }
        }
    }
    vector<int> ans(n);
    int c=0;
    for(int i = 0; i<sz(v); i++)
    {
        if(sz(v[i]))
            c++;
        for(int j = 0; j < sz(v[i]); j++)
        {
            ans[v[i][j]] = c;
        }
    }
    cout << m << endl;
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
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