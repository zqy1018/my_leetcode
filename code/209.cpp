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
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), ans = n + 1;
        for (int i = 0, j = -1, cnt = 0; i < n; ++i){
            while(j < n - 1 && cnt < s)
                ++j, cnt += nums[j];
            if(j == n - 1 && cnt < s) break;
            ans = min(ans, j - i + 1);
            cnt -= nums[i];
        }
        if(ans == n + 1) ans = 0;
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
