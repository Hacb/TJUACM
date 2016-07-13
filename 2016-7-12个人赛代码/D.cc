#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10003
#define M 16384
#define mod 1000000007

int a[N];
int dp[2][M];

int main() {
    int n, i, j;
    while (~scanf("%d", &n)) {
        for (i = 1;i <= n;i++) scanf("%d", a+i);
        int mx = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int now = 0, pre = 1;
        for (i = 1;i <= n;i++) {
            for (j = 0;j <= mx;j++) {
                mx = max(a[i]^j, mx);
                dp[pre][a[i]^j] = ((dp[pre][j^a[i]]+dp[now][j])%mod+dp[now][j])%mod;
                dp[pre][a[i]^j] += dp[now][a[i]^j];
                if (dp[pre][a[i]^j] >= mod) dp[pre][a[i]^j] -= mod;
            }
            now ^= 1, pre ^= 1;
            memset(dp[pre], 0, sizeof(dp[pre]));
        }
        //printf("%d\n", mx);
        printf("%d\n", dp[now][0]);
    }
}
