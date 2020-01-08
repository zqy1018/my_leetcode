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
    bool canThreePartsEqualSum(vector<int>& A) {
        vector<int> sum;
        int ss = 0, n = A.size();
        for (int i = 0; i < n; ++i){
            ss += A[i];
            sum.push_back(ss);
        }
        if(ss % 3) return false;
        set<int> st;
        st.insert(sum[0]);
        for (int i = 1; i < n; ++i){
            if((sum[i] & 1) == 0){
                if((sum[i] >> 1) * 3 == sum[n - 1])
                    if(st.count(sum[i] >> 1))
                        return true;
            }
            st.insert(sum[i]);
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
