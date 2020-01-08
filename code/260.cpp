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
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            res = (res ^ nums[i]);
        int bt = (res & (-res));
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i){
            if(bt & nums[i])
                a ^= nums[i];
            else 
                b ^= nums[i];
        }
        ans.push_back(a);
        ans.push_back(b);
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
