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
    int validSubarrays(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n + 3);
        for (int i = n - 1; i >= 0; --i){
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            if(st.empty()) res[i] = n;
            else res[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i){
            ans += 1ll * (res[i] - i);
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
