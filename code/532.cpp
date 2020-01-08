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
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0, cur = 0;
        if(!k){
            int n = nums.size();
            for (int i = 0; i < n; ){
                cur = i;
                while(cur < n && nums[i] == nums[cur])
                    ++cur;
                if(cur - i > 1) ans++;
                i = cur;
            }
            return ans;
        }
        int n = unique(nums.begin(), nums.end()) - nums.begin();
        
        for (int i = 0; i < n; ++i){
            while(cur < n && nums[cur] < k + nums[i])
                ++cur;
            if(cur < n && nums[cur] - nums[i] == k) ans++;
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
