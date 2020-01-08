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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> f(n, 2147483647);
        for (int i = 0; i < n; ++i){
            *lower_bound(f.begin(), f.end(), nums[i]) = nums[i]; 
        }
        return lower_bound(f.begin(), f.end(), 2147483647) - f.begin();
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
