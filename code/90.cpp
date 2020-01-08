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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		int n = nums.size(), siz = 1;
		vector<pair<int, int> > pp;
		for (int i = 0; i < n; )	{
			int j = i;
			while(j < n && nums[i] == nums[j])
				++j;
			pp.push_back(make_pair(nums[i], j - i));
			siz *= j - i + 1, i = j;
		}
		vector<vector<int> > ans(1, vector<int>(0));
		for (pair<int, int> &prop: pp){
			int cnt = prop.second;
			int cursiz = ans.size();
			for (int i = 0; i < cnt; ++i)
				for (int j = 0; j < cursiz; ++j)
					ans.push_back(ans[j]);	
			for (int i = 0; i < cnt; ++i)
				for (int j = 0; j < cursiz; ++j)
					for(int k = 0; k <= i; ++k)
						ans[(i + 1) * cursiz + j].push_back(prop.first);
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
