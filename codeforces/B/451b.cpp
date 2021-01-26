#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pr(x){for(int zz=0;zz<sz(x);zz++){cout<<x[zz]<<" ";}cout<<endl;}
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
    vector<int> arr(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i], b[i] = arr[i];
    sort(allr(b));
    reverse(all(arr));
    // pr(b);
    // pr(arr);
    int start = 0, end = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            start = i;
            break;
        }
    }
    end=start;
    for(int i = start; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            break;
        }
        end++;
    }
    // cout << start << " " << end << endl;
    reverse(arr.begin() + start, arr.begin() + end+1);
    // pr(arr);
    bool f = true;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != b[i])
        {
            f = false;
            break;
        }

    }
    int temp = start;
    start = n-end;
    end = n-temp;
    if(!f)
    {
        cout << "no";
    }
    else
    {
        cout << "yes\n";
        cout << start << " " << end;
    }
    return 0;
}