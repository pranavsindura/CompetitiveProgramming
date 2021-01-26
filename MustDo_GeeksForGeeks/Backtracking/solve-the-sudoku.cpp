/*
    Solve Sudoku
    Any one solution
*/

/*
    Approach -
    Can be done with backtracking
    At each step, find a 0
    If no zeroes are there that means the sudoku is solved
    Now try to place all numbers that can be placed on this position, General Sudoku rules
    then recursively solve for the remaining empty tiles
    If any of the children tell you that they were solved, keep this number
    Else just return false

    Assumes that atleast 1 solution is possible
*/
vector<vector<int>> ans;

bool can_place(int num, int r, int c, vector<vector<int>> &sudoku)
{
    // should not have num in same column
    for(int i = 0; i < 9; i++)
        if(sudoku[i][c] == num)
            return false;
    // should not have num in same row
    for(int j = 0; j < 9; j++)
        if(sudoku[r][j] == num)
            return false;
    // should not have num in box
    int box_r = r / 3;
    int box_c = c / 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(sudoku[i + box_r * 3][j + box_c * 3] == num)
                return false;
    return true;
}

bool solve(vector<vector<int>> &sudoku)
{
    bool found_zero = false;
    int x = -1, y = -1;
    for(int i = 0; i < 9 && !found_zero; i++)
    {
        for(int j = 0; j < 9 && !found_zero; j++)
        {
            if(sudoku[i][j] == 0)
            {
                found_zero = true;
                x = i, y = j;
            }
        }
    }
    if(!found_zero)
    {
        ans = sudoku;
        return true;
    }
    // found 0 at x,y
    for(int k = 1; k <= 9; k++)
    {
        if(can_place(k, x, y, sudoku))
        {
            sudoku[x][y] = k;
            bool was_solved = solve(sudoku);
            if(was_solved)
                return was_solved;
            sudoku[x][y] = 0;
        }
    }

    return false;
}

void cp()
{
    vector<vector<int>> sudoku(9, vector<int>(9, 0));
    ans = sudoku;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cin >> sudoku[i][j];
    solve(sudoku);
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cout << ans[i][j] << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}