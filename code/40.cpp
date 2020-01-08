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
    int tg, sz;
    void dfs(int id, int cur, vector<int>& nums){
        if(cur == tg){
            ans.push_back(tmp);
            return ;
        }
        if(id == sz) return ;
        int j = id;
        while(j < sz && nums[j] == nums[id]) ++j;
        for (int i = 1; i <= j - id; ++i){
            tmp.push_back(nums[id]);
            if(cur + nums[id] * i <= tg) 
                dfs(j, cur + nums[id] * i, nums);
            else break;
        }
        while(!tmp.empty() && tmp.back() == nums[id]) tmp.pop_back();
        dfs(j, cur, nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tg = target, sz = candidates.size();
        dfs(0, 0, candidates);
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
