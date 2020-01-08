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
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int> > f(n, vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < n - 2; ++i) 
            f[i][i + 2] = A[i] * A[i + 1] * A[i + 2];
        for (int i = 0; i < 2; ++i) 
            for (int j = 0; j + i < n; ++j)
                f[j][j + i] = 0;
        for (int i = 3; i < n; ++i)
            for (int j = 0; j + i < n; ++j)
                for (int k = j + 1; k < i + j; ++k)
                    f[j][i + j] = min(f[j][i + j], f[j][k] + f[k][i + j] + A[j] * A[j + i] * A[k]);
        return f[0][n - 1];
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
