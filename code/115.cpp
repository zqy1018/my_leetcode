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
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned> > f(n + 1, vector<unsigned>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
            f[i][0] = 1;
        for (int j = 0; j < m; ++j){
            for (int i = 0; i < n; ++i){
                if(s[i] == t[j]){
                    f[i + 1][j + 1] = f[i][j] + f[i][j + 1];
                }else{
                    f[i + 1][j + 1] = f[i][j + 1];
                }
            }
        }
        return f[n][m];
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
