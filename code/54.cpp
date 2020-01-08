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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return vector<int>();
        int m = matrix[0].size();
        vector<int> ans;
        for (int i = 0, j = 0; i < ((n + 1) >> 1) && j < ((m + 1) >> 1); ++i, ++j){
            for (int t = j; t < m - j; ++t)
                ans.push_back(matrix[i][t]);
            for (int t = i + 1; t < n - i - 1; ++t)
                ans.push_back(matrix[t][m - j - 1]);
            if(n - i - 1 != i){
                for (int t = m - j - 1; t >= j; --t)
                    ans.push_back(matrix[n - i - 1][t]);
            }
            if(m - j - 1 != j){
                for (int t = n - i - 2; t > i; --t)
                    ans.push_back(matrix[t][j]);
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
