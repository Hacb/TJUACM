#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10000001

int sum[N][9];
bool pri[N] = {0};
int cnt[N] = {0};

int main() {
    int s = 0;
    int j, tm = 1, i;
    for (i = 2;i < N;i++) {
        if (!pri[i]) {
            cnt[i] = 1;
            for (j = i+i;j < N;j+=i) {
                pri[j] = 1;
                cnt[j]++;
            }
        }
    }
    memset(sum, 0, sizeof(sum));
    for (i = 2;i < N;i++) {
        for (j = 0;j < 9;j++) {
            sum[i][j] = sum[i-1][j];
        }
        sum[i][cnt[i]]++;
    }
    int T, A, B, K, ca = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &A, &B, &K);
        printf("Case #%d: ", ca++);
        if (K > 8) puts("0");
        else {
            printf("%d\n", sum[B][K]-sum[A-1][K]);
        }
    }
}
