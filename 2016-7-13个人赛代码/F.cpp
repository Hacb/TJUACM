#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<string>
using namespace std;
int a,n;
int num[110];
int main()
{
    while(scanf("%d %d",&n,&a)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        int ans=0;
        if(num[a])ans++;
        int j;
        for(j=1;a+j<=n&&a-j>=1;j++)
        {
            if(num[a+j]+num[a-j]==2)
                ans+=2;
        }
        if(a+j>n)
        {
            for(int i=a-j;i>=1;i--)
                if(num[i])
                ans++;
        }
        else
        {
            for(int i=a+j;i<=n;i++)
                if(num[i])
                ans++;
        }
        printf("%d\n",ans);
    }

}
