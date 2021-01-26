/*
	Box Stacking
	Find max height that can be achieved
	If we can stack boxes on top of one another, use any amount of times

	Condition is that the base of box below must be bigger than the current box
	Not only in terms of area but also length and width
*/

/*
	Approach - DP

		We can convert it into an LIS problem
		We will first find all possible permutations of the Boxes
		And then Sort them in descending order and then maximise sum of the heights in the LIS
*/

/*The function takes an array of heights, width and
length as its 3 arguments where each index i value
determines the height, width, length of the ith box.
Here n is the total no of boxes.*/
typedef tuple<int, int, int> box;
int maxHeight(int height[], int width[], int length[], int n)
{
    vector<box> arr;
    for(int i = 0; i < n; i++)
    {
        int l = length[i];
        int b = width[i];
        int h = height[i];
        arr.push_back(make_tuple(l, b, h));
        arr.push_back(make_tuple(l, h, b));
        arr.push_back(make_tuple(b, h, l));
        arr.push_back(make_tuple(b, l, h));
        arr.push_back(make_tuple(h, l, b));
        arr.push_back(make_tuple(h, b, l));
    }
    //Sort in descending for maximum height!
    sort(arr.rbegin(), arr.rend());
    // Modify into LIS type dp
    int m = arr.size();
    int dp[m + 1];
    for(int i = 0; i < m; i++)
    {
        int l, b, h;
        tie(l, b, h) = arr[i];
        dp[i] = h;
        for(int j = 0; j < i; j++)
        {
            int l2, b2;
            tie(l2, b2, ignore) = arr[j];
            if(l2 > l && b2 > b)
                dp[i] = max(dp[i], dp[j] + h);
        }
    }
    return *max_element(dp, dp + m);
}