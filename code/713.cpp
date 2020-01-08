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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size(), ans = 0, anslst = 0, cur = 0;
        vector<int> numss;
        for (int i = 0; i < n; ++i){
            if(nums[i] == 1){
                int j = i; 
                while(j < n && nums[j] == 1)
                    ++j;
                numss.push_back(i - j), cur++;
                ans += anslst * (j - i) + (j - i) * (j - i + 1) / 2, i = j - 1;
            }else{
                numss.push_back(nums[i]), cur++;
                int j = cur - 1, res = 1, bs = 0;
                for (; j >= 0; --j){
                    if(numss[j] < 0) bs += -numss[j], bs--;
                    else{
                        if(res * numss[j] >= k) break;
                        res *= numss[j];
                    }
                }
                anslst = cur - 1 - j + bs;
                ans += anslst;
            }
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
