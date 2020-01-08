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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n, 1), bef(n, -1);
        int ans = 0, maxi = -1;
        for(int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if(nums[j] % nums[i]) continue;
                if(f[i] + 1 > f[j]) f[j] = f[i] + 1, bef[j] = i;
            }
            if(f[i] > ans) ans = f[i], maxi = i; 
        }
        vector<int> aans;
        for (int i = 0, j = maxi; i < ans; ++i, j = bef[j])
            aans.push_back(nums[j]);
        return aans;
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
