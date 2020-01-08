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
    int removeDuplicates(vector<int>& nums) {
        int cur = 0, n = nums.size();
        for (int i = 0; i < n; ){
            int j = i;
            while(j < n && nums[i] == nums[j])
                ++j;
            int tmp = nums[i];
            for (int t = min(j - i, 2); t > 0; --t){
                nums[cur++] = tmp;
            }
            i = j;
        }
        return cur;
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
