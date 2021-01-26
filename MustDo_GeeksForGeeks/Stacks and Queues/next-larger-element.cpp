/*
	Find NEXT LARGER ELEMENT OF AN ARRAY
*/

/*
	Approach 1 - Brute Force, Use 2 for loops to find next larger element O(n^2)
	Approach 2 - Stack
	Check if there are elements smaller than arr[i] in stack, for all of them answer is arr[i], pop and set
	Push arr[i] onto stack
	If stack is not empty for all of the remaining numbers there is no answer
*/
ll arr[MAXN];
ll ans[MAXN];
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] < arr[i])
        {
            int t = st.top();
            st.pop();
            ans[t] = arr[i];
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int t = st.top();
        st.pop();
        ans[t] = -1;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
