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
    vector<vector<int> > ans, ff;
    vector<int> tmp;
    void dfs(int cur, int maxi){
        if(!cur){
            ans.push_back(tmp);
            return ;
        }
        for (int w: ff[cur]){
            if(w > maxi) continue;
            tmp.push_back(w);
            dfs(cur - w, w);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> f(target + 1, 0);
        f[0] = true;
        ff = vector<vector<int> >(target + 1, vector<int>());
        for (int w: candidates)
            for (int i = w; i <= target; ++i)
                if(f[i - w]) f[i] = true, ff[i].push_back(w);
        dfs(target, 2147483647);
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
