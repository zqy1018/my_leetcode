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
    vector<vector<int>> vec;
    int kInversePairs(int n, int k) {
        vec = vector<vector<int>>(n + 1, vector<int>(k + 1, 0));
        vec[0][0] = 1;
        for (int i = 1; i <= n; ++i){
            vec[i][0] = 1;
            for (int j = 1; j <= k; ++j){
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
                if (vec[i][j] >= 1000000007)    
                    vec[i][j] -= 1000000007;
                if (j >= i){
                    vec[i][j] += 1000000007 - vec[i - 1][j - i];
                    if (vec[i][j] >= 1000000007)    
                        vec[i][j] -= 1000000007;
                }
            }
        }
        return vec[n][k];
    }
};
Solution sol;
void init(){
    cout << sol.kInversePairs(1000, 1111) << endl;
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
