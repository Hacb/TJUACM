#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
int n, m;
int num[1010];
set<int>zero, two;
set<int>::iterator t0,t2;
int p;
void update(int p,int add) {
    if(num[p]==0)zero.erase(p);
    if(num[p]==2)two.erase(p);
    num[p]+=add;
    printf(" %d %d",p,num[p]);
    if(num[p]==0)zero.insert(p);
    if(num[p]==2)two.insert(p);
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
        zero.insert(i);
    two.insert(n);
    while(m--)
    {
        scanf("%d",&p);
        t2=two.upper_bound(p);
        t0=zero.upper_bound(*t2);
        if(p>=*(--t0))
        {
            printf("3");
            update(p,1);
            update(*t2,-2);
            update(*t2+1,1);
        }
        else if(num[p]>0)
        {
            printf("2");
            update(p,-1);
            update(p+1,1);
        }
        else
        {
            printf("1");
            update(p,1);
        }
        puts("");
    }
}
