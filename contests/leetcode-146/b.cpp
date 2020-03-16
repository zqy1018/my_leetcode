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

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int> > dis(2 * n, vector<int>(2 * n, 0x3f3f3f3f));
        vector<int> ans(2 * n, 0x3f3f3f3f);
        vector<bool> vis(2 * n, false);
        for (int i = 0; i < red_edges.size(); ++i){
            dis[red_edges[i][0]][red_edges[i][1] + n] = 1;
        }
        for (int i = 0; i < blue_edges.size(); ++i){
            dis[blue_edges[i][0] + n][blue_edges[i][1]] = 1;
        }
        for (int i = 0; i < n + n; ++i)
            dis[i][i] = 0;
        ans[0] = ans[n] = 0;
        for (int i = 0; i < n + n; ++i){
            int minidis = 0x3f3f3f3f + 1, mini = -1;
            for (int j = 0; j < n + n; ++j)
                if(ans[j] < minidis && !vis[j])
                    minidis = ans[j], mini = j;
            vis[mini] = true;
            for (int j = 0; j < n + n; ++j){
                if(ans[mini] + dis[mini][j] < ans[j])
                    ans[j] = ans[mini] + dis[mini][j];
            }
        }
        vector<int> ans1(n, -1);
        ans1[0] = 0;
        for (int i = 1; i < n; ++i){
            int res = 0x3f3f3f3f;
            res = min(res, ans[i]);
            res = min(res, ans[i + n]);
            if(res < 0x3f3f3f3f) ans1[i] = res;
        }
        return ans1;
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
