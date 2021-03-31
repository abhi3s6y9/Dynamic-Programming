#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define F(i, a, b) for(ll i=a; i<=b; i++)
#define ll long long
#define INF 1000000009
#define mod 1000000007

ll n, m, a[2005], b[2005];
ll dp[2005][2005][8];

ll f(ll i, ll j, ll k)
{
	if (i==n || j==m)
	{
		// If any string is finished, ans is 0
		return 0;
	}
	// If current state has already been computed
	if(dp[i][j][k]!=-1)
	{
		return dp[i][j][k];
	}
	ll res=0;

	if(a[i]==b[j])
	{
		res = 1 + f(i+1, j+1, k);
	}
	else
	{
		if (k>0)
		{
			// We have converted a single char to match with jth character of string b
			res = 1 + f(i+1, j+1, k-1);
		}
		res = max(res, f(i, j+1, k));
		res = max(res, f(i+1, j, k));
	}

	return dp[i][j][k] = res;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	ll k;
	cin>>n>>m>>k;

	F(i, 0, n-1)
		cin>>a[i];

	F(i, 0, m-1)
		cin>>b[i];

	ll ans = f(0, 0, k);
	cout<<ans<<endl;

	return 0;
}
