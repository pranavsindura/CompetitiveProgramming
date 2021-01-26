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
int arr[32];
bool np=false;
int hanoi(int n, int from, int to, int aux)
{
	if(n==0)
		return 0;
	if(arr[n-1] == from)
		return hanoi(n-1, from, aux, to);
	else if(arr[n-1] == to)
		return ((1<<(n-1)) + hanoi(n-1,aux,to,from));
	return np = true;
}

int main()
{
    FASTIO;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    int ans = hanoi(n,1,2,3);
    if(np)
    	cout<<-1;
    else
    	cout<<ans;
    return 0;
}