#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    double s=0,t=1e9;
    for(int i=0;i<60;i++)
    {
        double mid=(s+t)*0.5;
        double l1,r1,l2,r2;
        l1 = min(min((a-mid)*(d-mid),(a-mid)*(d+mid)),min((a+mid)*(d-mid),(a+mid)*(d+mid)));
        r1 = max(max((a-mid)*(d-mid),(a-mid)*(d+mid)),max((a+mid)*(d-mid),(a+mid)*(d+mid)));
        l2 = min(min((b-mid)*(c-mid),(b-mid)*(c+mid)),min((b+mid)*(c-mid),(b+mid)*(c+mid)));
        r2 = max(max((b-mid)*(c-mid),(b-mid)*(c+mid)),max((b+mid)*(c-mid),(b+mid)*(c+mid)));
        if(l2>r1||l1>r2)s=mid;
        else t=mid;
    }
    printf("%.9f\n",(s+t)/2);
}