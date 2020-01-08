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
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return vector<vector<int> >();
        int m = matrix[0].size();
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        vector<vector<int> > ans(n, vector(m, -1));
        queue<int> qx, qy;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if(!matrix[i][j]) ans[i][j] = 0, qx.push(i), qy.push(j);
        while(!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if(ex < 0 || ex >= n || ey < 0 || ey >= m) continue;
                if(ans[ex][ey] < 0) 
                    ans[ex][ey] = ans[cx][cy] + 1, 
                    qx.push(ex), qy.push(ey);
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
