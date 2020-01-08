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
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size(), ans = 0;
        vector<int> f(n + 1, 0);
        f[0] = 1;
        int ss = 0;
        for (int i = 0; i < n; ++i){
            ss += A[i];
            if(ss - S >= 0) ans += f[ss - S];
            f[ss]++;
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
