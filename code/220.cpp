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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if(!n || !k) return false;
        multiset<long long> st;
        multiset<long long>::iterator it;
        for (int i = 0; i < k; ++i){
            it = st.lower_bound(1ll * nums[i] - t);
            if(it != st.end() && *it - t <= nums[i])
                return true;
            st.insert(nums[i]);
        }
        for (int i = k; i < n; ++i){
            it = st.lower_bound(1ll * nums[i] - t);
            if(it != st.end() && *it - t <= nums[i])
                return true;
            st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
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
