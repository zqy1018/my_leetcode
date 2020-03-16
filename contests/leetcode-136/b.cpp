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
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        queue<int> tp;
        vector<vector<int> > G(N, vector<int>());
        int m = paths.size();
        for (int i = 0; i < m; ++i)  
            G[paths[i][0] - 1].push_back(paths[i][1] - 1), 
            G[paths[i][1] - 1].push_back(paths[i][0] - 1);
        vector<int> ans(N, 0), fbd(N, 0);
        for (int i = 0; i < N; ++i){
            if(!ans[i]){
                ans[i] = 1;
                tp.push(i);
                for (int v: G[i]){
                    if(!ans[v]) fbd[v] |= (1 << 1);
                }
                while(!tp.empty()){
                    int u = tp.front();
                    tp.pop();
                    for (int j: G[u]){
                        if(!ans[j]){
                            int unused = 1;
                            while(((1 << unused) & fbd[j]))
                                unused++;
                            ans[j] = unused, tp.push(j);
                            for (int v: G[j]){
                                if(!ans[v]) fbd[v] |= (1 << ans[j]);
                            }
                        }
                    }
                }
            }
        }
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
