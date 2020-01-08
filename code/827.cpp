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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size(), tot_island = 0;
        vector<pair<int, int> > q;
        vector<int> siz;
        auto v = [&grid, &q, dx, dy, n, m](int x, int y){
            int hd = q.size(), tl = hd;
            q.push_back(make_pair(x, y)), ++tl;
            grid[x][y] = -1;
            while(tl > hd){
                x = q[hd].first, y = q[hd].second, ++hd;
                for (int i = 0; i < 4; ++i){
                    int cx = x + dx[i], cy = y + dy[i];
                    if(cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                    if(grid[cx][cy] < 0 || grid[cx][cy] == 0) continue;
                    grid[cx][cy] = -1;
                    q.push_back(make_pair(cx, cy)), ++tl;
                }
            }
        };
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if(grid[i][j] == 1){
                    int lst = q.size();
                    v(i, j), ++tot_island;
                    for (int k = lst; k < q.size(); ++k)
                        grid[q[k].first][q[k].second] = -tot_island;
                    siz.push_back(q.size() - lst), ans = max(ans, siz.back());
                }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if(grid[i][j] == 0){
                    int tot = 1;
                    for (int k = 0; k < 4; ++k){
                        int cx = i + dx[k], cy = j + dy[k];
                        if(cx < 0 || cy < 0 || cx >= n || cy >= m || grid[cx][cy] == 0) continue;
                        if (siz[-grid[cx][cy] - 1] < 0) continue;
                        tot += siz[-grid[cx][cy] - 1], siz[-grid[cx][cy] - 1] = -siz[-grid[cx][cy] - 1];
                    }
                    ans = max(tot, ans);
                    for (int k = 0; k < 4; ++k){
                        int cx = i + dx[k], cy = j + dy[k];
                        if(cx < 0 || cy < 0 || cx >= n || cy >= m || grid[cx][cy] == 0) continue;
                        if (siz[-grid[cx][cy] - 1] > 0) continue;
                        siz[-grid[cx][cy] - 1] = -siz[-grid[cx][cy] - 1];
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
