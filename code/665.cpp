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
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        bool used = false;
        for (int i = 0; i < n - 1; ++i){
            if(nums[i] > nums[i + 1]){
                if(!used) {
                    used = true;
                    bool u1 = true, u2 = true;
                    if(i > 0 && nums[i - 1] > nums[i + 1]) u1 = false;
                    if(i < n - 2 && nums[i + 2] < nums[i]) u2 = false;
                    if(!u1 && u2) nums[i + 1] = nums[i];
                    else if(!u1 && !u2) return false; 
                }else return false;
            }
        }
        return true;
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
