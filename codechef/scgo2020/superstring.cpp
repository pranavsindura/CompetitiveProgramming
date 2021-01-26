#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int find_overlap(string s1, string s2, string &str) 
{ 

    int mx = INT_MIN; 
    int ln1 = s1.length(); 
    int ln2 = s2.length(); 
  
    for (int i = 1; i <= min(ln1, ln2); i++) 
    { 
        if (s1.compare(ln1-i, i, s2, 0, i) == 0) 
        { 
            if (mx < i) 
            { 
                mx = i; 
                str = s1 + s2.substr(i); 
            } 
        } 
    } 
  
    for (int i = 1; i <= min(ln1, ln2); i++) 
    { 
        if (s1.compare(0, i, s2, ln2-i, i) == 0) 
        { 
            if (mx < i) 
            { 
                mx = i; 
                str = s2 + s1.substr(i); 
            } 
        } 
    } 
  
    return mx; 
} 
  
string solve(string arr[], int len) 
{ 
    while(len != 1) 
    { 
        int mx = INT_MIN;   
        int l, r;   
        string resStr; 
  
        for (int i = 0; i < len; i++) 
        { 
            for (int j = i + 1; j < len; j++) 
            { 
                string str; 
                int res = find_overlap(arr[i], arr[j], str); 
                if (mx < res) 
                { 
                    mx = res; 
                    resStr.assign(str); 
                    l = i, r = j; 
                } 
            } 
        } 
  
        len--;
        if (mx == INT_MIN) 
            arr[0] += arr[len]; 
        else
        { 
            arr[l] = resStr;
            arr[r] = arr[len];
        } 
    } 
    return arr[0]; 
} 

int main()
{
	FASTIO;
	int n;
	cin>>n;
	string arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	string ans = solve(arr, n);
	cout<<ans;
}