#include<cstdio>

long long a[100][100], b[100];

int main() {
    int n, i, j;
    while (~scanf("%d", &n)) {
        long long sum = 0;
        for (i = 0;i < n;i++) {
            b[i] = 0;
            for (j = 0;j < n;j++) {
                scanf("%I64d", &a[i][j]);
                b[i] += a[i][j];
                sum += a[i][j];
            }
        }
        long long tm = sum/(n-1);
        for (i = 0;i < n;i++) {
            a[i][i] = tm-b[i];
        }
        for (i = 0;i < n;i++) {
            for (j = 0;j < n;j++) {
                if (j) printf(" ");
                printf("%I64d", a[i][j]);
            }
            puts("");
        }
    }
}
