/*
	Check if 4 points form a square

	If ABCD is a quadrilateral
	To be a square
	1. All sides must be same length
	2. Diagonals must be equal
	3. All angles must be 90


	We will fix point A and check different arrangements of BCD

	A ----------B
	| \
	|  \
	|   \
	|    \
	|     \
	|      \
	|   	\ 
	|   	 \ 
	|   	  \
	|   	   D
	C
	
	We will check the following conditions
	1. AB = BC
	2. AD = sqrt(2) * AB
	3. BC = sqrt(2) * BD

	We can check these for arrangements of BDC, DBC, BCD

*/

// distance squared
int len(point a, point b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool check(point a, point b, point c, point d)
{
    int d2 = len(a, b);
    int d3 = len(a, c);
    int d4 = len(a, d);

    if(d2 == 0 || d3 == 0 || d4 == 0)
        return false;
    if(d2 == d3 && d4 == 2 * d2 && len(b, c) == 2 * len(b, d))
        return true;
    if(d3 == d4 && d2 == 2 * d4 && len(c, d) == 2 * len(b, d))
        return true;
    if(d2 == d4 && d3 == 2 * d2 && len(b, d) == 2 * len(b, c))
        return true;
    return false;
}