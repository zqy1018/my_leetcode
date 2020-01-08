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
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum;
        int ss = 0, ans = -2000000000;
        for (int i = 0; i < n; ++i){
            ss += nums[i];
            sum.push_back(ss);
            int res;
            if(i >= k) res = ss - sum[i - k];
            else if(i == k - 1) res = ss;
            else res = -2000000000;
            ans = max(ans, res);
        }
        return 1.0 * ans / k;
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
