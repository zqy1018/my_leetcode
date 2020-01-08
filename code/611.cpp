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
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 2; ++i){
            if(!nums[i]) continue;
            for (int j = i + 1; j < n - 1; ++j){
                if(!nums[j]) continue;
                if(nums[i] + nums[j] <= nums[j + 1])
                    continue;
                int id = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
                ans += id - j - 1;
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
