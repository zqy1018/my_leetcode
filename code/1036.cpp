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

bool vis[420][420];
class Solution {
public:
    set<pair<int, int> > st;
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for (auto &vec: blocked)    {
            st.insert(make_pair(vec[0], vec[1]))  ;
        }
        stack<int> qx, qy, step;
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

        int maxi_step = 0;
        memset(vis, 0, sizeof(vis));
        qx.push(source[0]), qy.push(source[1]), step.push(0);
        vis[0 + 205][0 + 205] = true;
        while (!qx.empty()){
            int cx = qx.top(), cy = qy.top(), curs = step.top();
            qx.pop(), qy.pop(), step.pop();
            if (cx == target[0] && cy == target[1]) return true;
            if (curs == 205) break;
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ey < 0 || ex >= 1000000 || ey >= 1000000)
                    continue;
                if (st.count(make_pair(ex, ey))) continue;
                if (vis[ex - source[0] + 205][ey - source[1] + 205])
                    continue;
                vis[ex - source[0] + 205][ey - source[1] + 205] = true;
                maxi_step = max(maxi_step, curs + 1);
                qx.push(ex), qy.push(ey), step.push(curs + 1);
            }
        }
        while (!qx.empty())
            qx.pop(), qy.pop(), step.pop();
        if (maxi_step < 205) return false;

        maxi_step = 0;
        memset(vis, 0, sizeof(vis));
        qx.push(target[0]), qy.push(target[1]), step.push(0);
        vis[0 + 205][0 + 205] = true;
        while (!qx.empty()){
            int cx = qx.top(), cy = qy.top(), curs = step.top();
            qx.pop(), qy.pop(), step.pop();
            if (curs == 205) continue;
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ey < 0 || ex >= 1000000 || ey >= 1000000)
                    continue;
                if (st.count(make_pair(ex, ey))) continue;
                if (vis[ex - target[0] + 205][ey - target[1] + 205])
                    continue;
                vis[ex - target[0] + 205][ey - target[1] + 205] = true;
                maxi_step = max(maxi_step, curs + 1);
                qx.push(ex), qy.push(ey), step.push(curs + 1);
            }
        }
        if (maxi_step < 205) return false;
        return true;
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
