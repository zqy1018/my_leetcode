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
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> f(n), d(n);
        f[0] = d[0] = 1;
        int ans = 1, ans1 = 0;
        for (int i = 1; i < n; ++i){
            f[i] = 1;
            for (int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    if(f[j] + 1 == f[i]) d[i] += d[j];
                    else if(f[j] + 1 > f[i]) d[i] = d[j], f[i] = f[j] + 1;
                }
            }
            if(!d[i]) d[i]++;
            ans = max(ans, f[i]);
        }
        for (int i = 0; i < n; ++i) 
            if(ans == f[i]) ans1 += d[i];
        return ans1;
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
