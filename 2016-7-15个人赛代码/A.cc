#include<cstdio>
#include<cstring>

char s[100022];

int main() {
    while(~scanf("%s", s)) {
        printf("%s", s);
        for (int i = strlen(s)-1;i >= 0;i--) printf("%c", s[i]);
        puts("");
    }
}
