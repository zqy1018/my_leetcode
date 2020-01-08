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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), ans = 0;
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2){
            if (v1[0] == v2[0]) return v1[1] < v2[1];
            return v1[0] < v2[0];
        });
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    f[i] = max(f[i], f[j] + 1);
            }
        }
        for (int i = 0; i < n; ++i)
            ans = max(ans, f[i]);
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
    int T = read();
    while (T--){
 init();
    solve();
    }
    return 0;
}
