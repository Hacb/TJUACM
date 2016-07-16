#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 110

int a[N][N], r[N][2], c[N][2];
bool vis[N][2];

int main() {
    int n, m, i, j;
    while (~scanf("%d%d", &n, &m)) {
        memset(vis, false, sizeof(vis));
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for (i = 0;i < n;i++) {
            for (j = 0;j < m;j++) {
                scanf("%d", &a[i][j]);
                if (a[i][j] > 0) {
                    r[i][0] += a[i][j];
                    c[j][0] += a[i][j];
                }else {
                    r[i][1] -= a[i][j];
                    c[j][1] -= a[i][j];
                }
            }
        }
        while (1) {
            int mx = 0, id, f = -1;
            for (i = 0;i < n;i++) {
                if (r[i][0] >= r[i][1]) continue;
                if (r[i][1] > mx) {
                    mx = r[i][1];
                    id = i, f = 0;
                }
            }
            for (i = 0;i < m;i++) {
                if (c[i][0] >= c[i][1]) continue;
                if (c[i][1] > mx) {
                    mx = c[i][1];
                    id = i, f = 1;
                }
            }
            if (f == -1) break;
            vis[id][f] ^= 1;
            if (f) {
                swap(c[id][0], c[id][1]);
                for (i = 0;i < n;i++) {
                    r[i][0] -= a[i][id];
                    r[i][1] += a[i][id];
                    a[i][id] = -a[i][id];
                }
            }else {
                swap(r[id][0], r[id][1]);
                for (i = 0;i < m;i++) {
                    c[i][0] -= a[id][i];
                    c[i][1] += a[id][i];
                    a[id][i] = -a[id][i];
                }
            }
        }
        int c1 = 0, c2 = 0;
        for (i = 0;i < n;i++) {
            c1 += vis[i][0];
        }
        for (i = 0;i < m;i++) {
            c2 += vis[i][1];
        }
        printf("%d", c1);
        for (i = 0;i < n;i++) {
            if (vis[i][0]) printf(" %d", i+1);
        }
        puts("");
        printf("%d", c2);
        for (i = 0;i < m;i++) {
            if (vis[i][1]) printf(" %d", i+1);
        }
        puts("");
    }
}
