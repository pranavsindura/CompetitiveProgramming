#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
int arr[MAXN];
/*
    Count Triplets, arr[x] + arr[y] = arr[z]

    Approach 1 - Brute Force O(n^3)
    Pick 2 and see if sum exists in array

    Approach 2 - Brute force with Hashing O(n^2logn) or O(n^2)
    Pick 2 and see if sum exists in array, only you create a map/frequency array which tells if it exists

    Approach 3 - Sliding Window and sorting O(n^2)
    Sort array, go from biggest number to smallest
    Have two pointers l=0, r=i-1
    and manipulate them according to if sum > arr[i], == or <
*/

// 2
void cp()
{
    clr(cnt, false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]] = true;
    }
    int triplet_count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(cnt[arr[i] + arr[j]])
                triplet_count++;
        }
    }
    if(triplet_count)
        cout << triplet_count << endl;
    else
        cout << -1 << endl;
}

// 3
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int triplet_count = 0;
    for(int i = n - 1; i > 0; i--)
    {
        int l = 0, r = i - 1;
        while(l < r)
        {
            int sum = arr[l] + arr[r];
            if(sum > arr[i])
            {
                r--;
            }
            else if(sum == arr[i])
            {
                triplet_count++;
                l++, r--;
            }
            else
            {
                l++;
            }
        }
    }
    if(triplet_count)
        cout << triplet_count << endl;
    else
        cout << -1 << endl;
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