#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int t,n,cas,cnt;
int sum[10010],prime[10010],ph[10010];
bool flag[10010];
int main()
{
	sum[1]=2;
	for(int i=2;i<=10000;i++)
	{
		if(!flag[i])
		{
			ph[i]=i-1;
			prime[cnt++]=i;
		}
		for(int j=0;j<cnt&&i*prime[j]<=10000;j++)
		{
			flag[i*prime[j]]=true;
			if(i%prime[j]==0)
			{
				ph[i*prime[j]]=ph[i]*prime[j];
				break;
			}
			else ph[i*prime[j]]=ph[i]*(prime[j]-1);
		}
	}
	for(int i=2;i<=10000;i++)
		sum[i]=sum[i-1]+ph[i];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&cas,&n);
		printf("%d %d\n",cas,sum[n]);
	}
}