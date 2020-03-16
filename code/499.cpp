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
    int dis[1005][1005][4];
    int roll(vector<vector<int>>& grid, int startX, int startY, int endX, int endY) {
        if (grid[startX][startY] || grid[endX][endY]) return -1;
        if (startX == endX && startY == endY) return 0;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        int n = grid.size(), m = grid[0].size();
        memset(dis, 0x3f, sizeof(dis));
        queue<int> qx, qy, qd;
        for (int i = 0; i < 4; ++i){
            dis[startX][startY][i] = 1;
            qx.push(startX), qy.push(startY), qd.push(i);
        }

        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front(), cd = qd.front();
            qx.pop(), qy.pop(), qd.pop();
            int eex = cx + dx[cd], eey = cy + dy[cd];
            if (eex < 0 || eey < 0 || eex >= n || eey >= m || grid[eex][eey]) {
                if (cx == endX && cy == endY) return dis[cx][cy][cd];
                for (int i = 0; i < 4; ++i){
                    if (dis[cx][cy][i] <= dis[cx][cy][cd] + 1)
                        continue;
                    dis[cx][cy][i] = dis[cx][cy][cd] + 1;
                    qx.push(cx), qy.push(cy), qd.push(i);
                }
            }else {
                if (dis[eex][eey][cd] <= dis[cx][cy][cd]) 
                    continue;
                dis[eex][eey][cd] = dis[cx][cy][cd];
                qx.push(eex), qy.push(eey), qd.push(cd);
            }
        }
        return -1;
    }
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        
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
