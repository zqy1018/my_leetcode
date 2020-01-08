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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), hf = n >> 1;
        for (int i = 0; i < hf; ++i){
            for (int j = i; j < n - i - 1; ++j){
                int r1 = matrix[i][j], r2 = matrix[j][n - i - 1], 
                    r3 = matrix[n - i - 1][n - j - 1], r4 = matrix[n - j - 1][i];
                matrix[j][n - i - 1] = r1;
                matrix[n - i - 1][n - j - 1] = r2;
                matrix[n - j - 1][i] = r3;
                matrix[i][j] = r4;
            }
        }
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
