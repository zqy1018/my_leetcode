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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        set<long long> st;
        st.insert(0);
        int n = nums.size(), ans = 0;
        long long ss = 0;
        for (int i = 0; i < n; ++i){
            ss += 1ll * nums[i];
            ans += distance(st.lower_bound(ss - upper), st.upper_bound(ss - lower));
            st.insert(ss);
        }
        //Si - Sj >= lower -> Sj <= Si - lower
        //Si - Sj <= upper -> Sj >= Si - upper
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
