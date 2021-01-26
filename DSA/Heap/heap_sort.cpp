#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

// O(logN)
void heapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}

void heap_sort(vector<int> &arr)
{
    // Leaf nodes start from N/2 to N
    // Build Heap from last actual root so that max element floats to top
    // O(N * logN)
    int n = sz(arr);
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);
    // Now swap Heap's top with last element, reduce length and heapify again
    // O(N)
    for(int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }

}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    heap_sort(arr);

    for(int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}