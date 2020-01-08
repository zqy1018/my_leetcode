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


//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
class BFS{
public:
    
};

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
class Solution {
public:
    queue<int> qx, qy;
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                if (A[i][j]) {
                    A[i][j] = 2, qx.push(i), qy.push(j);
                    goto label;
                }
        label:
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (A[ex][ey] != 1) continue;
                A[ex][ey] = 2, qx.push(ex), qy.push(ey);
            }
        }
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j){
                if (A[i][j] != 0) continue;
                bool flag = false;
                for (int d = 0; d < 4; ++d){
                    int ex = i + dx[d], ey = j + dy[d];
                    if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                        continue;
                    if (A[ex][ey] == 2) {
                        flag = true;
                        break;
                    }
                }
                if (flag) A[i][j] = -1, qx.push(i), qy.push(j);
            }
        int ans = INT_MAX;
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (A[ex][ey] != 0) continue;
                A[ex][ey] = A[cx][cy] - 1, qx.push(ex), qy.push(ey);
            }
        }
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j){
                if (A[i][j] != 1) continue;
                for (int d = 0; d < 4; ++d){
                    int ex = i + dx[d], ey = j + dy[d];
                    if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                        continue;
                    if (A[ex][ey] < 0) ans = min(ans, -A[ex][ey]);
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
