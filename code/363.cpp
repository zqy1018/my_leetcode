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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size(), ans = INT_MIN;
        if (!m) return 0;
        vector<vector<int> > sum(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i + 1][j] + matrix[i][j];
        set<int> st;
        for (int i = 1; i <= m; ++i){
            for (int j = i; j <= m; ++j){
                st.clear();
                st.insert(0);
                int ssm = 0;
                for (int t = 1; t <= n; ++t){
                    ssm += sum[t][j] - sum[t][i - 1];
                    auto iter = st.lower_bound(ssm - k);
                    if (iter != st.end())
                        ans = max(ans, ssm - *iter);
                    st.insert(ssm);
                }
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
