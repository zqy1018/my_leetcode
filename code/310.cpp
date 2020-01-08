#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return f * x; 
}

int to[100005], nxt[100005], at[50005], cnt;
int d1[50005], d2[50005], dd[50005];
class Solution {
public:
    void dfs1(int cur, int fa){
        for(int i = at[cur]; i; i = nxt[i]){
            if (fa == to[i]) continue;
            int v = to[i];
            dfs1(v, cur);
            if (d1[v] + 1 > d1[cur]){
                if (d2[v] + 1 > d1[cur]) d2[cur] = d2[v] + 1;
                else d2[cur] = d1[cur];
                d1[cur] = d1[v] + 1;
            }else if (d1[v] + 1 == d1[cur]){
                d2[cur] = d1[v] + 1;
            }else {
                if (d1[v] + 1 > d2[cur]) d2[cur] = d1[v] + 1;
            }
        }
        if (d1[cur] < 0) d1[cur] = 0;
    }
    void dfs2(int cur, int fa){
        for(int i = at[cur]; i; i = nxt[i]){
            if (fa == to[i]) continue;
            int v = to[i]; 
            dd[v] = d1[v];
            if (d1[v] + 1 == d1[cur]){
                if (d1[v] + 1 == d2[cur])
                    dd[v] = max(dd[v], d1[cur] + 1);
                else {
                    if (d2[cur] >= 0)
                        dd[v] = max(dd[v], d2[cur] + 1);
                }
            } else 
                dd[v] = max(d1[cur] + 1, dd[v]);
            if (dd[v] )
            dfs2(v, cur);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        memset(at, 0, sizeof(at));
        cnt = 0;
        for (auto& e: edges){
            int u = e[0], v = e[1];
            to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
            to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
        }
        memset(d1, 0x90, sizeof(d1));
        memset(d2, 0x90, sizeof(d2));
        dfs1(0, -1);
        dd[0] = d1[0];
        dfs2(0, -1);
        int mini = n + 1;
        for (int i = 0; i < n; ++i)
            mini = min(mini, dd[i]);
        vector<int> ans;
        for (int i = 0; i < n; ++i) 
            if(dd[i] == mini) ans.push_back(i);
        return ans;
    }
};
Solution sol;
void init(){
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
