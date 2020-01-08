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
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int j = ((n + 1) >> 1);
        auto it = (nums.begin() + j);
        nth_element(nums.begin(), it, nums.end());
        int lp = 0, rp = n - 1;
        while (lp < j && rp > j){
            while (lp < j && nums[lp] < nums[j])
                ++lp;
            while (rp > j && nums[rp] >= nums[j])
                --rp;
            if (lp == j || rp == j) break;
            swap(nums[lp++], nums[rp--]);
        }
        for (int i = 1; i >= 0; --i)
            nums[i + i] = nums[i];  
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
