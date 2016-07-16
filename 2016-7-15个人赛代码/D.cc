#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100002

bool vis[N];
int ans[N];

int main() {
    int n, i, j, k;
    while (~scanf("%d%d", &n, &k)) {
        memset(vis, false, sizeof(vis));
        int cnt = 0;
        ans[cnt++] = n;
        vis[n] = true;
        int tm = -1;
        for (i = k;i >= 1;i--) {
            ans[cnt] = ans[cnt-1]+i*tm;
            vis[ans[cnt++]] = true;
            tm *= -1;
        }
        for (i = n;i >= 1;i--) {
            if (vis[i]) continue;
            ans[cnt++] = i;
        }
        for (i = 0;i < n;i++) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
}


