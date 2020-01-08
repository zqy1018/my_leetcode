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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, 0));
        for (int i = 0, u = 1; i < ((n + 1) >> 1); ++i){
            for (int t = i; t < n - i; ++t, ++u)
                ans[i][t] = u;
            for (int t = i + 1; t < n - i - 1; ++t, ++u)
                ans[t][n - i - 1] = u;
            if(n - i - 1 != i){
                for (int t = n - i - 1; t >= i; --t, ++u)
                    ans[n - i - 1][t] = u;
                for (int t = n - i - 2; t > i; --t, ++u)
                    ans[t][i] = u;
            }
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
