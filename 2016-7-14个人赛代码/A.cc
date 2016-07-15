#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Tr{
    int num[120];
    Tr operator+(Tr a)const {
        Tr tm;
        memset(tm.num, 0, sizeof(tm.num));
        int in = 0, i, j;
        for (i = 0;i < 120;i++) {
            tm.num[i] = (num[i]+a.num[i]+in)%10;
            in = (num[i]+a.num[i]+in)/10;
        }
        return tm;
    }
    bool operator==(Tr a)const{
        int i;
        for (i = 119;i >= 0;i--) {
            if (num[i] != a.num[i]) return false;
        }
        return true;
    }
}A, B, C;

char a[110], b[110], c[110];

int main() {
    int i, j;
    while (~scanf("%s%s%s", a, b, c)) {
        memset(A.num, 0, sizeof(A.num));
        memset(B.num, 0, sizeof(B.num));
        memset(C.num, 0, sizeof(C.num));
        int la = strlen(a), lb = strlen(b), lc = strlen(c);
        for (i = la-1;i >= 0;i--) A.num[la-1-i] = a[i]-'0';
        for (i = lb-1;i >= 0;i--) B.num[lb-1-i] = b[i]-'0';
        for (i = lc-1;i >= 0;i--) C.num[lc-1-i] = c[i]-'0';
        if (A+B == C || A+C == B || B+C==A) puts("YES");
        else if (A+A == C || B+B==C || B+B==A || C+C == B || C+C == A || A+A==B) puts("YES");
        else puts("NO");
    }
}
