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
    bool canJump(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        st.push(n);
        st.push(n - 1);
        for (int i = n - 2; i >= 0; --i){
            while(st.size() > 1 && i + nums[i] >= st.top())
                st.pop();
            st.push(i);
        }
        st.pop();
        return st.top() == n;
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
