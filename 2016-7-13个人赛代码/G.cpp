#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<string>
using namespace std;
int a[5];
int num[110];
int main()
{
    while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4])!=EOF)
    {
        sort(a,a+5);
        int ans=0;
        memset(num,0,sizeof(num));
        for(int i=0;i<5;i++)
        {
            ans+=a[i];
            num[a[i]]++;
        }
        int mx=0;
        for(int i=100;i>=1;i--)
        {
            if(num[i]>=3)
            {
                mx=max(mx,i*3);
            }
            else if(num[i]==2)
            {
                mx=max(mx,i*2);
            }
        }
        printf("%d\n",ans-mx);
    }

}
