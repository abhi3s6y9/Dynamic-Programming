#include <iostream>
#include <cstring>
using namespace std;

int memo[100][100];

int maxProfit(int arr[],int begin, int end, int year)
{
    if(begin>end)
        return 0;
    
    if(memo[begin][end]!=-1) return memo[begin][end];
    
    int p1 = arr[begin]*year + maxProfit(arr, begin+1, end, year+1);
    int p2 = arr[end]*year + maxProfit(arr, begin, end-1, year+1);
    
    memo[begin][end] = max(p1, p2);
    return memo[begin][end];
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
    memset(memo, -1, sizeof(memo));
    
    cout<<maxProfit(arr, 0, n-1, 1);
    
    return 0;
}
