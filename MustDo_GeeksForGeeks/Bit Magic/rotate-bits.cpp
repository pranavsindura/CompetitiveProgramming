/*
	Rotate Bits of Number N, D times
	Both left and right
	Number of bits in each number = 16
*/

/*
	Approach 1 -
		First of all modulo D with the length of the number i.e. 16 bits
		Left rotate and right rotate D times to get answer
*/
// 16 bit number
int rot_left(int n)
{
    n <<= 1;
    // Get 16th bit
    int bit = (n >> 16) & 1;
    // Clear 16th bit
    n = n & (~(1 << 16));
    // Move 16th bit to position 0
    n |= bit;
    return n;
}

int rot_right(int n)
{
    int bit = n & 1;
    n >>= 1;
    n |= (bit << 15);
    return n;
}

void cp()
{
    int n, d;
    cin >> n >> d;
    d %= 16;
    int left = n;
    for(int i = 0; i < d; i++)
        left = rot_left(left);
    int right = n;
    for(int i = 0; i < d; i++)
        right = rot_right(right);
    cout << left << endl;
    cout << right << endl;
}