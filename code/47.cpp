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
    vector<bool> vis;
    vector<int> tmp;
    vector<vector<int> > ans;
    int n;
    void build(int id, int lst, vector<int>& nums){
        if(id == n) {
            ans.push_back(tmp);
            return ;
        }
        for (int i = (id && nums[id - 1] == nums[id]) ? lst + 1: 0; i < n; ++i){
            if(vis[i]) continue;
            tmp[i] = nums[id], vis[i] = true;
            build(id + 1, i, nums);
            vis[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        if(!n) return ans;
        sort(nums.begin(), nums.end());
        tmp.resize(n);
        vis = vector<bool>(n, false);
        build(0, -1, nums);
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
