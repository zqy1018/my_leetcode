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
    int maxCoins(vector<int>& nums) {
		nums.push_back(1);
		nums.insert(nums.begin(), 1);
		int n = nums.size();
        vector<vector<int> > f(n, vector<int>(n, 0));
        for (int i = 2; i < n; ++i)
			for (int j = 0; j + i < n; ++j)
				for (int k = j + 1; k < j + i; ++k)	
					f[j][j + i]	= max(f[j][i + j], f[j][k] + f[k][j + i] + nums[k] * nums[i + j] * nums[j]); 
		return f[0][n - 1];
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
