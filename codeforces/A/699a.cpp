#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n, x;
    string s;
    cin >> n >> s;
    vector<int> left, right;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(s[i] == 'L')
            left.push_back(x / 2);
        else
            right.push_back(x / 2);
    }
    sort(all(left));
    sort(all(right));
    int ans = INT_MAX;
    bool collide = false;
    for(int i = 0; i < right.size(); i++)
    {
        vector<int>::iterator f = upper_bound(all(left), right[i]);
        if(f == left.end())
            continue;
        else
        {
            collide = true;
            ans = min(*f - right[i], ans);
        }
    }
    if(collide)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}