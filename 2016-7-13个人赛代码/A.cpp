#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<string>
using namespace std;
char mp[55][55];
bool foo(int a,int b)
{
    int cnt[4]={};
    for(int i=a;i<=a+1;i++)
    {
        for(int j=b;j<=b+1;j++)
        {
            if(mp[i][j]=='f')
                cnt[0]++;
            else if(mp[i][j]=='a')
                cnt[1]++;
            else if(mp[i][j]=='c')
                cnt[2]++;
            else if(mp[i][j]=='e')
                cnt[3]++;
        }
    }
    if(cnt[0]==1&&cnt[1]==1&&cnt[2]==1&&cnt[3]==1)
        return true;
    return false;
}
int main()
{
    int n,m,ans;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf(" %c",&mp[i][j]);
            }
        }
        ans=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                if(foo(i,j))
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
}