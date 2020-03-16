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
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int lim = n * m;
        int ans = 100000;
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < (1 << lim); ++i){
            int cnt = 0;
            int tmp = i;
            while (tmp > 0)
                cnt += ((tmp & 1) ? 1: 0), tmp >>= 1;
            auto ttmp = mat;
            for (int j = 0; j < lim; ++j){
                if (!((1 << j) & i)) continue;
                int cx = j / n, cy = j % n;
                ttmp[cx][cy] ^= 1;
                for (int d = 0; d < 4; ++d){
                    int ex = cx + dx[d], ey = cy + dy[d];
                    if (ex < n && ex >= 0 && ey < m && ey >= 0)
                        ttmp[ex][ey] ^= 1;
                }
            }
            bool flag = true;
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < m; ++k)
                    if (ttmp[j][k]) {
                        flag = false;
                        break;
                    }
            if (flag) ans = min(ans, cnt);
        }
        if (ans == 100000) return -1;
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
