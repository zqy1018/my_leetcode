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
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; ++i){
            int lim = max(0, i - K);
            int maxi = -2147483648;
            for (int j = i - 1; j >= lim; --j){
                maxi = max(maxi, A[j]);
                f[i] = max(f[i], f[j] + maxi * (i - j));
            }
        }
        return f[n];
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
