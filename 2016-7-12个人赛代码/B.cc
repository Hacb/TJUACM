#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100001

long long dp[N][2];
int a[N];

int main() {
    int n, i, j;
    while (~scanf("%d", &n)) {
        for (i = 0;i < n;i++) scanf("%d", a+i);
        sort(a, a+n);
        memset(dp, -1, sizeof(dp));
        dp[1][0] = a[1]-a[0];
        for (i = 2;i < n;i++) {
            dp[i][0] = dp[i-1][0]+a[i]-a[i-1];
            dp[i][1] = dp[i-1][0];
            if (dp[i-1][1] == -1) continue;
            dp[i][0] = min(dp[i][0], dp[i-1][1]+a[i]-a[i-1]);
        }
        printf("%I64d\n", dp[n-1][0]);
    }
}
