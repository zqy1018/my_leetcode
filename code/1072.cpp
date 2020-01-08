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
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        bitset<301> bs[305], bs2[305], vis;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                if (matrix[i][j]) bs[i].set(j);
                else bs2[i].set(j);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i){
            if (vis.test(i))
                continue;
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                if (bs[i] == bs[j] || bs[i] == bs2[j])
                    ++cnt, vis.set(j);
            ans = max(ans, cnt);
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
