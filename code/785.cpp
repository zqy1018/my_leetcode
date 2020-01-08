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
class Solution {
public:
    vector<int> col;
    int flag;
    void dfs(int cur, int d, vector<vector<int>>& graph){
        col[cur] = d;
        for (int to: graph[cur]){
            if(col[to] < 0) dfs(to, d ^ 1, graph);
            else if(col[to] != (d ^ 1)) flag = 0;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        col = vector<int>(n, -1);
        flag = 1;
        for (int i = 0; i < n; ++i)
            if(col[i] < 0) dfs(i, 0, graph);
        return flag;
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
