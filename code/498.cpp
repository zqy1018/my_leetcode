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
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return vector<int>(0);
        int m = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < n + m - 1; ++i){
            if(i & 1){
                for (int j = max(0, i - m + 1); j < n && j <= i; ++j)
                    ans.push_back(matrix[j][i - j]);
            }else{
                for (int j = max(0, i - n + 1); j < m && j <= i; ++j)
                    ans.push_back(matrix[i - j][j]);
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
