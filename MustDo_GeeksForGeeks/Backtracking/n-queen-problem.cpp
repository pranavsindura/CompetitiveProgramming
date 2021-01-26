/*
	Find all ways to place N queens in an NxN chess board
*/
/*
	Approach - Backtracking
	Loop on columns
	Keep track of all the rows, diags which have queens
	Try to place in every row in which it can be placed
*/

vector<vector<int>> ans;
bool row[11], diag1[2 * 11], diag2[2 * 11];
int n;
vector<int> cur;
void n_queen(int col)
{
    if(col == n)
    {
        ans.pb(cur);
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            // try to place queen in ith row
            if(!row[i] && !diag1[i + col] && !diag2[i - col + n])
            {
                row[i] = true;
                diag1[i + col] = true;
                diag2[i - col + n] = true;

                cur.pb(i);
                n_queen(col + 1);
                cur.pop_back();

                row[i] = false;
                diag1[i + col] = false;
                diag2[i - col + n] = false;
            }
        }
    }
}

void cp()
{
    cin >> n;
    ans.clear();
    n_queen(0);
    if(ans.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for(int i = 0; i < sz(ans); i++)
        {
            cout << "[";
            for(int x : ans[i])
                cout << x + 1 << " ";
            cout << "] ";
        }
        cout << endl;
    }
}
