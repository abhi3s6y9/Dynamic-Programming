#include <iostream>
using namespace std;

int maxProfitDP(int arr[], int n)
{
    int dp[n][n];
    int year = n;
    
    for(int i=0;i<n;i++)
    {
        dp[i][i] = arr[i]*year;
    }
    
    while(year>1)
    {
        year--;
        for(int i=0, j=n-year; i<n-i-1, j<n; i++, j++)
        {
            dp[i][j] = max(dp[i][j-1] + arr[j]*year,  dp[i+1][j] + arr[i]*year);
        }
    }
    
    return dp[0][n-1];
}

int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxProfitDP(arr,n);
    
    return 0;
}
