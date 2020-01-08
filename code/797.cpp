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
    vector<vector<int> > ans;
    vector<int> tmp;
    int T;
    void dfs(int cur, vector<vector<int>>& graph){
        tmp.push_back(cur);
        if(cur == T){
            ans.push_back(tmp);
            tmp.pop_back();
            return ;
        }
        for (int to: graph[cur])
            dfs(to, graph);
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        T = graph.size() - 1;
        dfs(0, graph);
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
