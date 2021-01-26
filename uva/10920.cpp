#include <iostream>

using namespace std;

typedef long long ll;

ll size, p, x, y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> size >> p, size||p) {
	ll i = 1;
	while(p > i*i) i+=2; // find the ring containing p

	// 1 is a special case
	if(i == 1) {
	    cout << "Line = " << (size/2)+1 << ", column = " << (size/2)+1 << ".\n";
	    continue;
	}

	// find the side of the ring containing p
	// lb is the "lower bound" to start our search from
	// pad is the number of squares of "padding" the ring has from the outside
	ll lb = (i-2)*(i-2), pad = (size-i)/2;
	if(p <= lb + i-1) {
	    // NORTH side
	    x = lb+i-p+pad;
	    y = size-pad;
	} else if(lb + i-1 < p && p <= lb + 2*(i-1)) {
	    // WEST side
	    x = pad+1;
	    y = lb+(i-1)*2+1-p+pad;
	} else if(lb + 2*(i-1) < p && p <= lb + 3*(i-1)) {
	    // SOUTH side
	    x = p-(lb+2*(i-1))+pad+1;
	    y = pad+1;
	} else {
	    // EAST side
	    x = size-pad;
	    y = p-(lb+3*(i-1))+pad+1;
	}

	cout << "Line = " << y << ", column = " << x << ".\n";
    }
	
    return 0;
}