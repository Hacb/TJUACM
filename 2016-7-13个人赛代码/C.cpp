#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<string>
using namespace std;
int n,m;
char mp[110][110];
int num[110][110];
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                scanf(" %c",&mp[i][j]);

        }
        memset(num,0,sizeof(num));
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(mp[i][j]=='B'&&num[i][j]!=1)
                {
                    ans++;
                    int temp=1-num[i][j];
                    for(int k=0;k<=i;k++)
                    {
                        for(int l=0;l<=j;l++)
                        {
                            num[k][l]+=temp;
                        }
                    }
                }
                if(mp[i][j]=='W'&&num[i][j]!=-1)
                {
                    ans++;
                    int temp=-1-num[i][j];
                    for(int k=0;k<=i;k++)
                    {
                        for(int l=0;l<=j;l++)
                        {
                            num[k][l]+=temp;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}