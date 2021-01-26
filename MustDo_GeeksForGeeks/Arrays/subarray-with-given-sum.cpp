#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAXN = 1e7 + 5;
ll arr[MAXN];

/*SUBARRAY WITH GIVEN SUM*/
/*
    POSITIVE ARRAY NUMBERS
    Simple Approach - O(n^3)
    See all subarrays and check if sum is equal to required sum

    With prefix array - O(n^2)
*/
/*
    Two Pointer Concept - O(n)
    If window sum is smaller than required add more elements i.e. increase right side
    If sum is equal to required then OKAY! print it
    else if sum is greater increment left side and decrease window
*/

//POSITIVE NUMBERS
void cp()
{
    int n;
    ll s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0, j = 0;
    ll sum = arr[0];
    while(i < n && j < n)
    {
        if(sum < s)
        {
            j++;
            if(j < n)
                sum += arr[j];
        }
        else if(sum == s)
        {
            cout << i + 1 << " " << j + 1 << endl;
            return;
        }
        else
        {
            sum -= arr[i];
            i++;
        }
    }
    cout << -1 << endl;
}
//POSITIVE + NEGATIVE NUMBERS
/*
    NEGATIVE NUMBERS AND POSITIVE NUMBERS

    Approach 1 - Hash Map O(nlogn) or O(n)
    Let's say that subarray with sum S is x.......y
    pref(y) - pref(x-1) = S
    So we can have a hashmap different sums we have encountered before (their index or number of times depends on problem)
    Go linearly and then see if an index with sum = curr_sum-S exists

    READ AGAIN
    Approach 2 - Element shifting + Two Pointer O(n)
    We can shift every element by the smallest value in the array
    Thus, converting it to a Positive number only case! which can be solved with Sliding Window
    Target Sum will also be needed to be shifted for every window as,
    New_Target = Target + window_length * smallest_number
*/
map<ll,int> hash_sum;
void cp()
{
    hash_sum.clear();
    int n;
    ll s;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>s;
    ll sum = 0;
    int count_subarray = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(sum == s)
        {
            count_subarray++;
        }
        if(hash_sum.find(sum-s) != end(hash_sum))
        {
            count_subarray+=hash_sum[sum-s];
        }
        hash_sum[sum]++;
    }
    cout<<count_subarray<<endl;
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
}s