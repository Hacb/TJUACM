#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
using namespace std;

const int MAXN = 100 + 10;
char a[MAXN][6];
char tar[MAXN];
int n, t;
vector<int> g[26];
int link[MAXN];
bool vis[MAXN];

bool dfs(int u){
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!vis[v]){
            vis[v] = true;
            if(link[v] == -1 || dfs(link[v])){
                link[v] = u;
				return true;
            }
        }
    }
    return false;
}

int hungary(){
    int ans = 0;
    memset(link, -1, sizeof(link));
    for(int i = 0; i < t;++i){
        memset(vis, false, sizeof(vis));
        if(dfs(i)) {
			++ans;
		}
	}
    return ans;
}

int main(){
	std::cin >> tar >> n;
	for(int i = 0; i < n; ++i){
        for(int j = 0; j < 6; ++j){
			std::cin >> a[i][j];
        }
    }
	t = strlen(tar);
    for(int i = 0; i < t; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < 6; ++k){
                if(tar[i] == a[j][k]){
                    g[i].push_back(j);
				}
			}
        }
    }
    if(hungary() == t){
		std::cout << "YES\n";
	}else{
		std::cout << "NO\n";
	}
	return 0;
}
