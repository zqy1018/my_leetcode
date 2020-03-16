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

int dx[] = {-1, -1, -2, -2, 1, 1, 2, 2}, dy[] = {-2, 2, -1, 1, -2, 2, -1, 1};
int dis[1005][1005];
class Solution {
public:
    int minKnightMoves(int x, int y) {
        memset(dis, 0x3f, sizeof(dis));
        dis[500][500] = 0;
        queue<int> qx, qy;
        qx.push(500), qy.push(500);
        while (!qx.empty()){
            int ex = qx.front(), ey = qy.front();
            qx.pop(), qy.pop();
            if (500 + x == ex && 500 + y == ey)
                return dis[ex][ey];
            for (int i = 0; i < 8; ++i){
                int cx = ex + dx[i], cy = ey + dy[i];
                if (cx < 1 || cy < 1 || cx > 1000 || cy > 1000) continue;
                if (dis[cx][cy] == 0x3f3f3f3f){
                    dis[cx][cy] = dis[x][y]  + 1;
                    qx.push(cx) , qy.push(cy);
                }
            }
        }   
        return dis[500 + x][500 + y];
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
