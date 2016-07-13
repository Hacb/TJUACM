#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10001

int a[N];

int main() {
    int i, n;
    while (~scanf("%d", &n)) {
        for (i = 0;i < n;i++) scanf("%d", a+i);
        sort(a, a+n);
        for (i = n-1;i >= 3;i--) {
            if (a[i] < a[i-1]+a[i-2]+a[i-3] && a[i] != a[i-3]) break;
        }
        if (i < 3) puts("-1");
        else printf("%d\n", a[i]+a[i-1]+a[i-2]+a[i-3]);
    }
}
