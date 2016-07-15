#include<cstdio>
#include<cstring>
#define N 100003

char a[N];

int main() {
    int c1, c2, i, j;
    while (~scanf("%s", a)) {
        c1 = c2 = 0;
        for (i = 0;a[i];i++) {
            if (a[i] == '1') c1++;
            else c2++;
        }
        printf("%d\n", c1>c2?c2:c1);
    }
}
