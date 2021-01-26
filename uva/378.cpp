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
// P(x1,y1) Q(x2,y2)
// (y1 – y2)x + (x2 – x1)y + (x1y2 – x2y1) = 0
int main()
{
    FASTIO;
    int t;
    cin>>t;
    cout<<"INTERSECTING LINES OUTPUT\n";
    while(t--)
    {
    	int x1,y1,x2,y2,x3,y3,x4,y4;
    	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    	int a1=y1-y2;
		int b1=x2-x1;
		int c1=x1*y2-x2*y1;

		int a2=y3-y4;
		int b2=x4-x3;
		int c2=x3*y4-x4*y3;

		double det = a1*b2*1.0 - b1*a2*1.0;

    	if(det == 0)
    	{
    		if(a1*x3+b1*y3+c1 == 0)
    		{
    			cout<<"LINE\n";
    		}
    		else
    		{
    			cout<<"NONE\n";
    		}
    	}
    	else
    	{
    		double x = (b1*c2*1.0-b2*c1*1.0)/det;
			double y = (a2*c1*1.0-a1*c2*1.0)/det;
			cout<<"POINT "<<fixed<<setprecision(2)<<x<<" "<<fixed<<setprecision(2)<<y<<endl;
    	}
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}