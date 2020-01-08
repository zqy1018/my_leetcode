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

vector<vector<int>> vec{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
class Solution {
public:
    int knightDialer(int N) {
        int ans[10], tmp[10], M = 1000000007;
        for (int i = 0; i < 10; ++i)    
            ans[i] = 1, tmp[i] = 0;
        for (int i = 0; i < N - 1; ++i) {
            for (int t = 0; t < 10; ++t)
                for (int j: vec[t])
                    tmp[t] = (tmp[t] + ans[j] >= M ? tmp[t] + ans[j] - M: tmp[t] + ans[j]);
            for (int t = 0; t < 10; ++t)    
                ans[t] = tmp[t], tmp[t] = 0;
        }
        int aans = 0;
        for (int i = 0; i < 10; ++i)    
            aans = (aans + ans[i] >= M ? aans + ans[i] - M: aans + ans[i]);
        return aans;
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
