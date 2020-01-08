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
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        typedef pair<int, pair<int, int> > T;
        vector<T> vec;
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size(), ans = 0;
        vector<vector<int> > f(n, vector<int>(m, 1));
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                vec.push_back(make_pair(matrix[i][j], make_pair(i, j)));
        sort(vec.begin(), vec.end());
        for (T &t: vec){
            int h = t.first, x = t.second.first, y = t.second.second;
            for (int i = 0; i < 4; ++i){
                int cx = x + dx[i], cy = y + dy[i];
                if(cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                if(matrix[cx][cy] < h) f[x][y] = max(f[x][y], f[cx][cy] + 1);
            }
            ans = max(ans, f[x][y]);
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
