#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int t,cas;
long long n,m;
int dfs(long long n,long long m)
{
	if(n==1&&m==1)
	{
		return 1;
	}
	long long mn=min(n,m);
	long long mx=max(n,m);
	int ans;
	if(mn==n)
		ans=dfs(mn,mx-mn);
	else
		ans=dfs(mx-mn,mn);
	if(mn==n)
		return ans<<1;
	else
		return ans<<1|1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lld/%lld",&cas,&n,&m);
		printf("%d %d\n",cas,dfs(n,m));
	}
}
