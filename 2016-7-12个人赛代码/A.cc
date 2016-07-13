#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[5], n;
int ans;

void dfs(int sum, int d) {
    if (d == n) {
        ans = max(ans, sum);
        return;
    }
    int i, tm = sum+a[d], cnt = 0;
    int b[5], c[5];
    do {
        b[cnt++] = tm%10;
        tm /= 10;
    }while (tm != 0);
    for (i = 0;i < cnt;i++) c[i] = i;
    do {
        int re = 0;
        for (i = 0;i < cnt;i++) re = re*10+b[c[i]];
        dfs(re, d+1);
    }while (next_permutation(c, c+cnt));
}

int main() {
    int i, j;
    while (~scanf("%d", &n)) {
        for (i = 0;i < n;i++) scanf("%d", a+i);
        ans = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
}
