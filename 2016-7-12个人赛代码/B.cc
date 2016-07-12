#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000003

struct Tr{
    int s[26];
}tr[N];

int cntTr;

int cal(char *s) {
    int i, cnt = 0, root = 0;
    for (i = 0;s[i];i++) {
        int tm = s[i]-'a';
        if (tr[root].s[tm] == -1) {
            cnt++;
            return cnt;
        }
        root = tr[root].s[tm];
        cnt++;
    }
    return cnt;
}

void insert(char *s) {
    int i, root = 0;
    for (i = 0;s[i];i++) {
        int tm = s[i]-'a';
        if (tr[root].s[tm] == -1) {
            tr[root].s[tm] = ++cntTr;
            memset(tr[cntTr].s, -1, sizeof(tr[cntTr].s));
        }
        root = tr[root].s[tm];
    }
}
char s[N];

int main() {
    int n, T, ca = 1, i, j;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cntTr = 0;
        memset(tr[0].s, -1, sizeof(tr[0].s));
        long long ans = 0;
        for (i = 0;i < n;i++) {
            scanf("%s", s);
            ans += cal(s);
            insert(s);
        }
        printf("Case #%d: %I64d\n", ca++, ans);
    }
}
