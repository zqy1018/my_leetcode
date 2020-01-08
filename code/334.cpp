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
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return false;
        int lst = 2147483647;
        for (int i = 0; i < n; ++i){
            if(lst > nums[i]) lst = nums[i];
            else{
                if(i > 0 && nums[i - 1] > lst && nums[i] > nums[i - 1])
                    return true;
                else if(nums[i] > lst)
                    nums[i] = lst + 1;
            }
        }
        return false;
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
