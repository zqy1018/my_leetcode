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
    int findMaxLength(vector<int>& nums) {
        int ans = 0, ss = 0, n = nums.size();
        vector<int> vis(2 * n + 2, -1);
        vis[n] = 0;
        for (int i = 0; i < n; ++i){
            if(nums[i]) ss++;
            else ss--;
            if(vis[ss + n] >= 0) ans = max(ans, i + 1 - vis[ss + n]);
            else vis[ss + n] = i + 1;
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
