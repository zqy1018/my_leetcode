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

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, 0x3f3f3f3f));
        dis[0][0] = 0;
        queue<int> qx, qy;
        qx.push(0), qy.push(0);
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 8; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= n) 
                    continue;
                if (grid[ex][ey] || dis[cx][cy] + 1 >= dis[ex][ey]) 
                    continue;
                dis[ex][ey] = dis[cx][cy] + 1;
                qx.push(ex), qy.push(ey);
            }
        }
        return (dis[n - 1][n - 1] == 0x3f3f3f3f ? -1: dis[n - 1][n - 1]);
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
