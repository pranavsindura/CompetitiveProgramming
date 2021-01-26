/*
    STOCK BUY AND SELL
    Maximize profit
*/

/*
    Approach 1 - Buy a valley sell a peak O(n^2)
    Valley can start from any index so try all.
    Pick maximum profit
*/

const int MAXN = 1e3 + 5;
int arr[MAXN];
void cp()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    arr[0] = INT_MAX;
    arr[n + 1] = INT_MIN;

    vector<pi> max_trades;
    int max_profit = 0;

    for(int j = 1; j <= n; j++)
    {
        vector<pi> trades;
        pi trade = {-1, -1};
        bool valley = true;

        int profit = 0;
        
        for(int i = j; i <= n; i++)
        {
            if(arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
            {
                //valley
                if(valley)
                {
                    //buy
                    trade.ff = i;
                    valley = !valley;
                }
            }
            else if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            {
                //peak
                if(!valley)
                {
                    //sell
                    trade.ss = i;
                    profit += arr[trade.ss] - arr[trade.ff];
                    trades.pb(trade);
                    trade = {-1, -1};
                    valley = !valley;
                }
            }
        }

        if(profit > max_profit)
            max_profit = profit, max_trades = trades;
    }
    if(max_profit == 0)
    {
        cout << "No Profit\n";
    }
    else
    {
        for(pi x : max_trades)
        {
            cout << "(" << x.ff - 1 << " " << x.ss - 1 << ") ";
        }
        cout << endl;
    }
}