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
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cur = n - 1, cnt = 0, i;
		while (cur >= 0 && nums[cur] == 2) --cur;
        for (i = 0; i < cur; ++i){
            while (nums[i] != 0){
                if (nums[i] == 1) nums[i] = 2, ++cnt;
				swap(nums[cur], nums[i]);
				while (cur > i && nums[cur] == 2) --cur;
            }
        }
		for (int j = 0; j < cnt; ++j) nums[i + cnt] = 1;
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
