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
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double> > f(K + 1, vector<double>(n + 1, -1000000000.0));
        f[0][0] = 0;
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) 
            sum[i + 1] = sum[i] + A[i];
        for (int i = 1; i <= K; ++i)
            for (int j = i; j <= n; ++j)
                for (int k = j - i + 1; k > 0; --k)
                    f[i][j] = max(f[i][j], f[i - 1][j - k] + 1.0 * (sum[j] - sum[j - k]) / k);
        return f[K][n];
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
