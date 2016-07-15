#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int a[16], n, ans;
int dp[1<<16], b[16];

void cal(int *c, int st, int &cnt) {
    int i;
    for (i = 0;i < n;i++) {
        if (st&(1<<i)) {
            c[cnt++] = i;
        }
    }
}

int main() {
    int i, j, k, h;
    while (~scanf("%d", &n)) {
        for (i = 0;i < n;i++) scanf("%d", a+i);
        sort(a, a+n);
        int st = 1<<n, cnt;
        ans = 0;
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (i = 1;i < st;i++) {
            cnt = 0;
            cal(b, i, cnt);
            for (j = 0;j < cnt;j++) {
                for (k = j+1;k < cnt;k++) {
                    for (h = k+1;h < cnt;h++) {
                        int nst = i^(1<<b[j])^(1<<b[k])^(1<<b[h]);
                        if (dp[nst] == -1 || a[b[j]]+a[b[k]] <= a[b[h]]) continue;
                        dp[i] = max(dp[i], dp[nst]+1);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
}
