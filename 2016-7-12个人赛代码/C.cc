#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2001
#define mod 1000000007

int dp1[N][N], dp2[N][N];

int main() {
    int T, ca = 1, i, j, a, b;
    scanf("%d", &T);
    while (T--) {
        scanf("%d-%d", &a, &b);
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        dp1[1][0] = 1;
        for (i = 2;i <= a;i++) {
            for (j = 0;j < i;j++) {
                if (i-1 > j) {
                    dp1[i][j] += dp1[i-1][j];
                    if (dp1[i][j] >= mod) dp1[i][j] -= mod;
                }
                if (j) {
                    dp1[i][j] += dp1[i][j-1];
                    if (dp1[i][j] >= mod) dp1[i][j] -= mod;
                }
            }
        }
        dp2[0][0] = 1;
        for (i = 0;i <= a;i++) {
            for (j = 0;j <= b;j++) {
                if (i == 0 && j == 0) continue;
                if (i > j && i != 0) {
                    if (j == b) {
                        dp2[i][j] += dp2[i-1][j];
                        if (dp2[i][j] >= mod) dp2[i][j] -= mod;
                    }
                }else {
                    if (i) {
                        dp2[i][j] += dp2[i-1][j];
                        if (dp2[i][j] >= mod) dp2[i][j] -= mod;
                    }
                    if (j) {
                        dp2[i][j] += dp2[i][j-1];
                        if (dp2[i][j] >= mod) dp2[i][j] -= mod;
                    }
                }
            }
        }
        printf("Case #%d: %d %d\n", ca++, dp1[a][b], dp2[a][b]);
    }
}
