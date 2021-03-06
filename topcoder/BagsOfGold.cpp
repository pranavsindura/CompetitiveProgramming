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

class BagsOfGold
{
public:
    int netGain(vector <int>);
};

const int inf = 1e8;
vector<int> bags;

int dp[55][55][2];

int solve(int i, int j, int maxi_player)
{
    if(i > j)
        return 0;

    int &ret = dp[i][j][maxi_player];
    if(~ret)
        return ret;

    int ans = maxi_player ? -inf : inf;

    if(maxi_player)
    {
        // choose i
        ans = max(ans, bags[i] + solve(i + 1, j, 0));
        // choose j
        ans = max(ans, bags[j] + solve(i, j - 1, 0));
    }
    else
    {
        // choose i
        ans = min(ans, -bags[i] + solve(i + 1, j, 1));
        // choose j
        ans = min(ans, -bags[j] + solve(i, j - 1, 1));
    }
    return ret = ans;
}

int BagsOfGold::netGain(vector <int> bags)
{
    ::bags = bags;
    int n = sz(bags);
    clr(dp, -1);
    return solve(0, n - 1, 1);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	BagsOfGold *obj;
	int answer;
	obj = new BagsOfGold();
	clock_t startTime = clock();
	answer = obj->netGain(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {7,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {2,7,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1000,1000,1000,1000,1000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {823,912,345,100000,867,222,991,3,40000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -58111;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
