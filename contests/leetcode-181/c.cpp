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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
const int dir[][2] = {{2, 3}, {0, 1}, {2, 1}, {3, 1}, {0, 2}, {0, 3}};
const int consist[][6][2] = {
    {{1, 1}, {0, 0}, {0, 1}, {1, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}},
    {{1, 0}, {0, 1}, {0, 0}, {1, 0}, {0, 1}, {1, 1}},
    {{1, 0}, {0, 1}, {1, 0}, {0, 0}, {1, 1}, {0, 1}},
    {{0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 0}, {0, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 0}}
};
class Solution {
    queue<int> qx, qy;
    bool vis[305][305];
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        qx.push(0), qy.push(0);
        int n = grid.size(), m = grid[0].size();
        vis[0][0] = true;
        while (!qx.empty()){
            int x = qx.front(), y = qy.front();
            qx.pop(), qy.pop();
            for (int u = 0; u < 2; ++u){
                int cx = x + dx[dir[grid[x][y] - 1][u]], cy = y + dy[dir[grid[x][y] - 1][u]];
                if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                    continue;
                if (!consist[grid[x][y] - 1][grid[cx][cy] - 1] || vis[cx][cy]) continue;
                qx.push(cx), qy.push(cy), vis[cx][cy] = true;
            }
        }
        return vis[n - 1][m - 1];
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
