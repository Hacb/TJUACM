#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int t,n,cas;
int num1[10010],num2[10010],num3[10010];
int main()
{
	int temp1=1,temp2=1,temp3=2;
	for(int i=1;i<=10000;i++)
	{
		num1[i]=num1[i-1]+temp1;
		num2[i]=num2[i-1]+temp2;
		num3[i]=num3[i-1]+temp3;
		temp1++;
		temp2+=2;
		temp3+=2;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&cas,&n);
		printf("%d %d %d %d\n",cas,num1[n],num2[n],num3[n]);
	}
}