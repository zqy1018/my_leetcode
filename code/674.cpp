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
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for (int i = 0; i < n; ){
            int j = i + 1;
            while(j < n && nums[j] > nums[j - 1])
                ++j;
            ans = max(ans, j - i);
            i = j; 
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
