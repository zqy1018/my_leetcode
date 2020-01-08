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
    vector<int> nextGreaterElements(vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end());
        stack<int> st;
        int n = nums.size(), hf = nums.size() >> 1;
        vector<int> ans(hf, -1);
        for (int i = n - 1; i >= hf; --i){
            while(!st.empty() && nums[i] >= st.top())
                st.pop();
            st.push(nums[i]);
        }
        for (int i = hf - 1; i >= 0; --i){
            while(!st.empty() && nums[i] >= st.top())
                st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(nums[i]);
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
