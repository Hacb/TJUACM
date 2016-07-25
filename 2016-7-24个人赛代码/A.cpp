#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int t,n,cas;
long long ans[110];
long long C(int n,int m)
{
	long long ret=1;
	for(int i=1;i<=m;i++)
	{
		ret*=n;
		ret/=i;
		n--;
	}
	return ret;
}
int main()
{
	ans[1]=0;
	ans[2]=1;
	ans[3]=4;
	ans[4]=1;
	ans[5]=9;
	ans[6]=37;
	for(int i=7;i<=50;i++)
	{
		int cnt1=i/2;
		int cnt2=i%2;
		while(cnt1>=cnt2)
		{
			ans[i]+=C(cnt1+cnt2,cnt2)*C(cnt1+cnt2,cnt2);
			cnt1--;
			cnt2+=2;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&cas,&n);
		printf("%d %lld\n",cas,ans[n/2]);
	}
}