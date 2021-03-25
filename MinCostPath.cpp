#include <iostream>
using namespace std;

int minCost(int grid[][100], int r, int c)
{
    int dp[100][100];
    
    dp[0][0] = grid[0][0];
    
    for(int i=1;i<r;i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    
    for(int j=1;j<c;j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];
        
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    
    return dp[r-1][c-1];
}

int main()
{
    int grid[100][100] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3},
    };
    
    cout<<"Minimum cost path is "<<minCost(grid, 3, 3);
    
    return 0;
}
