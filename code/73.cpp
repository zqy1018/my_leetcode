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
    void setZeroes(vector<vector<int>>& matrix) {
        if(!matrix.size()) return ;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if(!matrix[i][j] || matrix[i][j] == 123456789){
                    for (int k = 0; k < n; ++k){
                        if(matrix[k][j] == 0) matrix[k][j] = 123456789;
                        else if(matrix[k][j] != 123456789) matrix[k][j] = 123456788;
                    }
                    for (int k = 0; k < m; ++k){
                        if(matrix[i][k] == 0) matrix[i][k] = 123456789;
                        else if(matrix[i][k] != 123456789) matrix[i][k] = 123456788;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if(matrix[i][j] == 123456788 || matrix[i][j] == 123456789) matrix[i][j] = 0;
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
