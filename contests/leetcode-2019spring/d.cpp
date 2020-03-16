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
    void dfs(int id){
        in[id] = true;
        for(int i = at[id]; i; i = e[i].nxt)
            if(!in[e[i].v]) dfs(e[i].v);
        st[top++] = id;
    }
    void rdfs(int id){
        in[id] = false;
        rk_cmp[id] = R;
        for(int i = at_[id]; i; i = e_[i].nxt)
            if(in[e_[i].v]) rdfs(e_[i].v);
    }
    void kosaraju(){
        for(int i = 1; i <= V; ++i)
            if(!in[i]) dfs(i);
        for(int i = top - 1; i >= 0; --i)
            if(in[st[i]]) R++, rdfs(st[i]);
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> in(n), loop(n);
        stack<int> st;
        vector<int> G[n], G_inv[n];
        int m = edges.size();
        for (int i = 0; i < m; ++i){
            int u = edges[i][0], v = edges[i][1];
            if(u == v) loop[u] = true;
            else G[u].push_back(v), G_inv[v].push_back(u);
        }
        
    }
};
bool in[10005] = {0}; 
int st[10005], top = 0;
void dfs(int id){
    in[id] = true;
    for(int i = at[id]; i; i = e[i].nxt)
        if(!in[e[i].v]) dfs(e[i].v);
    st[top++] = id;
}
void rdfs(int id){
    in[id] = false;
    rk_cmp[id] = R;
    for(int i = at_[id]; i; i = e_[i].nxt)
        if(in[e_[i].v]) rdfs(e_[i].v);
}
void kosaraju(){
    for(int i = 1; i <= V; ++i)
        if(!in[i]) dfs(i);
    for(int i = top - 1; i >= 0; --i)
        if(in[st[i]]) R++, rdfs(st[i]);
}
void init(){

}
void solve(){
	
}
int main(){
	init();
	solve();
	return 0;
}
