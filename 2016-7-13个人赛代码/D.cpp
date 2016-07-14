#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct node
{
    int id,v;
}num[200010];
bool cmp(node n1,node n2)
{
    return n1.id+n1.v<n2.id+n2.v;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i].v);
            num[i].id=i;
        }
        bool falg=true;
        sort(num,num+n,cmp);
        for(int i=0;i<n;i++)
        {
            num[i].v=num[i].id+num[i].v-i;
            if(num[i].v<0||(i>=1&&num[i].v<num[i-1].v))
            {
                falg=false;
                break;
            }
        }
        if(falg)
        {
            for(int i=0;i<n-1;i++)
                printf("%d ",num[i].v);
            printf("%d\n",num[n-1].v);
        }
        else
            puts(":(");
        }

}