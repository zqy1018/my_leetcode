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
    int rob(vector<int>& nums) {
        int lst1 = 0, lst2 = 0, n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int ans = 0;
        lst1 = 0, lst2 = nums[0];
        for (int i = 2; i < n - 1; ++i){
            int cur = max(lst1 - nums[i - 1], lst2) + nums[i];
            lst2 = lst1, lst1 = cur;
        }
        ans = max(lst1, lst2);
        lst1 = nums[1], lst2 = 0;
        for (int i = 2; i < n; ++i){
            int cur = max(lst1 - nums[i - 1], lst2) + nums[i];
            lst2 = lst1, lst1 = cur;
        }
        ans = max(ans, max(lst1, lst2));
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
