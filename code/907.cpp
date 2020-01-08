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
    int sumSubarrayMins(vector<int>& A) {
        stack<int> st;
		vector<int> l( A.size(), 0 );
		int ans = 0;
		for (int i = 0; i < A.size(); ++i){
			while ( !st.empty() && A[i] <= A[st.top()] ){
				int pos = st.top();
				st.pop();
				ans = ( ans + i *  ) % 1000000007;
			}
			st.push( i ); 
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
