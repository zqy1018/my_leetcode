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

int sm[305][305];
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        memset(sm, 0, sizeof(sm));
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j)
                sm[i + 1][j + 1] = sm[i + 1][j] + mat[i][j];
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j)
                sm[i + 1][j + 1] += sm[i][j + 1];
        }
        for (int l = min(n, m); l >= 1; --l){
            bool flag = true;
            for (int i = l; i <= n && flag; ++i)
                for (int j = l; j <= m; ++j){
                    if (sm[i][j] - sm[i - l][j] - sm[i][j - l] + sm[i - l][j - l] <= threshold) {
                        flag = false;
                        break;
                    }
                }
            if (!flag) return l;
        }
        return 0;
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
