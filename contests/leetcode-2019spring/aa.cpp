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
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 1; i < n; ++i){
            int gap = nums[i] - nums[i - 1] - 1;
            if(gap >= k){
                return nums[i - 1] + k;
            }else{
                k -= gap;
            }
        }
        return nums[n - 1] + k;
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
