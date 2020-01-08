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
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += A[i][0];
        if (cnt == 0){
            for (int i = 0; i < n; ++i) A[i][0] = 1;
        }else if (cnt < n){
            for (int i = 0; i < n; ++i){
                if (!A[i][0]){
                    for (int j = 0; j < m; ++j)
                        A[i][j] ^= 1;
                }
            }
        }
        for (int i = 1; i < m; ++i){
            cnt = 0;
            for (int j = 0; j < n; ++j)
                cnt += A[j][i];
            if (n - cnt > cnt) {
                for (int j = 0; j < n; ++j)
                    A[j][i] ^= 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i){
            int cur = 0;
            for (int j = 0; j < m; ++j)
                cur = (cur << 1) + A[i][j];
            ans += cur;
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
