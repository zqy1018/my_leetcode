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
        A.insert(A.end(), A.begin(), A.end());
        int nn = 2 * n;
        vector<vector<int> > f(nn + 1, vector<int>(nn + 1, 0));
        for (int i = 0; i < nn - 2; ++i)
            f[i][i + 2] = A[i] * A[i + 1] * A[i + 2];
        for (int i = 3; i < nn; ++i)
            for (int j = 0; j + i < nn; ++j)
                f[j][j + i] = 0x3f3f3f3f; 
        for (int i = 3; i < n; ++i){
            for (int j = 0; j + i < nn; ++j){
                for (int k = j + 1; k < i + j - 1; ++k)
                    for (int l = k + 1; l < i + j; ++l)
                        f[j][i + j] = min(f[j][i + j], f[j][k] + f[k][l] + f[l][j + i + 1] + A[j] * A[k] * A[l]);
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            ans = min(ans, f[i][i + n]);
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
