#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define N 200003

vector<pair<int,int> >V;

struct Tr{
    int id, in;
    bool operator<(const Tr a) const{
        return in < a.in;
    }
}tr[N];

int main() {
    int n, i, j;
    while (~scanf("%d", &n)) {
        V.clear();
        int sum = 0;
        for (i = 1;i <= n;i++) {
            scanf("%d", &tr[i].in);
            tr[i].id = i;
            sum += tr[i].in;
        }
        if (n == 1) {
            puts("");
            continue;
        }
        if (sum != 2*n-2) {
            printf("-1\n");
            continue;
        }
        queue<int>Q;
        while (!Q.empty()) Q.pop();
        sort(tr+1, tr+n+1);
        for (i = 1;i <= n;i++) {
            if (tr[i].in == 1) {
                Q.push(i);
            }else break;
        }
        int id = i;
        for (id;id < n;id++) {
            while (tr[id].in > 1 && !Q.empty()) {
                int u = Q.front();
                Q.pop();
                V.push_back(make_pair(tr[u].id, tr[id].id));
                tr[id].in--;
            }
            if (tr[id].in == 1) Q.push(id);
        }
        while (tr[id].in && !Q.empty()) {
            int u = Q.front();
            Q.pop();
            V.push_back(make_pair(tr[u].id, tr[id].id));
            tr[id].in--;
        }
        if (V.size() != n-1) puts("-1");
        else {
            for (i = 0;i < V.size();i++) {
                printf("%d %d\n", V[i].first, V[i].second);
            }
        }
    }
}
