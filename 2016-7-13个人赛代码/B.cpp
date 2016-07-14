#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<string>
using namespace std;
int main()
{
    int n,k,temp,cnt1,cnt2,t;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        t=n-k;
        cnt1=cnt2=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp&1)
                cnt1++;
            else
                cnt2++;
        }
        if(t==0)
        {
            if(cnt1&1)
                puts("Stannis");
            else
                puts("Daenerys");
        }
        else
        {
            if(cnt1<=t/2)
            {
                puts("Daenerys");
            }
            else
            {
                if(t&1)
                {
                    if(cnt2<=t/2&&!(k&1))
                        puts("Daenerys");
                    else
                        puts("Stannis");
                }
                else
                {
                    if(cnt2<=t/2&&(k&1))
                        puts("Stannis");
                    else
                        puts("Daenerys");
                }
            }
        }
    }
}

