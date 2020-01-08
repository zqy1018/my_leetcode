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

int to[2005], at[1005], nxt[2005], cnt;
bool vis[1005];
class Solution {
public:
	int res;
	set<pair<int, int>> st;
	void dfs(int cur, int fa){
		for (int i = at[cur]; i; i = nxt[i]){
			int v = to[i];
			if (vis[v] && v != fa)
				res = v;
			else if (!vis[v])
				vis[v] = true, dfs(v, cur);
		}
	}
	bool dfs2(int cur, int fa){
		for (int i = at[cur]; i; i = nxt[i]){
			int v = to[i];
			if (v == fa) continue ;
			if (v == res) return true;
			else if (dfs2(v, cur)) {
				if (v < cur)
					st.insert(make_pair(v, cur));
				else
					st.insert(make_pair(cur, v));
				return true;
			}
		}
		return false;
	}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		memset(at, 0, sizeof(at));
		memset(vis, 0, sizeof(vis));
		cnt = 0, res = 0;
		for (vector<int>& e: edges){
			int u = e[0], v = e[1];
			to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
			to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
		}
		vis[1] = true, dfs(1, 0);
		dfs2(res, 0);
		int n = edges.size();
		for (int i = n - 1; i >= 0; --i)
			if (st.count(make_pair(edges[i][0], edges[i][1])))
				return edges[i];
		return vector<int>();
    }
};
Solution sol;
void init(){
	vector<vector<int>> vec{{1, 2}, {2, 3}, {1, 3}};
    cout << sol.findRedundantConnection(vec)[1];
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
