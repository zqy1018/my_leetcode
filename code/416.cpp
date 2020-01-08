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
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), ss = 0;
        for (int v: nums) ss += v;
        if(ss & 1) return false;
        vector<bool> f((ss >> 1) + 1, false);
        f[0] = true;
        for (int i = 0; i < n; ++i){
            int v = nums[i];
            for (int j = (ss >> 1); j >= v; --j)
                if(f[j - v]) f[j] = true;
        }
        return f[ss >> 1];
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
