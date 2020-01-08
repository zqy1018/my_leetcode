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
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int max1 = 0, maxi = -1, max2 = 0;
        for (int i = 0; i < n; ++i){
            if(nums[i] > max1) max2 = max1, max1 = nums[i], maxi = i;
            else if(nums[i] < max1 && nums[i] > max2) max2 = nums[i];
        }
        return max1 >= max2 * 2 ? maxi: -1;
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
