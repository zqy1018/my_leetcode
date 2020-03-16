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
    vector<pair<int, int>> vecm[1005], vecp[1005];
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), p = B[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i][j] != 0)
                    vecm[i].push_back(make_pair(j, A[i][j]));
        for (int j = 0; j < p; ++j)
            for (int i = 0; i < n; ++i)
                if (B[i][j] != 0)
                    vecp[j].push_back(make_pair(i, B[i][j]));
        vector<vector<int>> ans(m, vector<int>(p, 0));
        for (int i = 0; i < m; ++i) {
            if (vecm[i].empty()) continue;
            int sizm = vecm[i].size();
            auto& vm = vecm[i];
            for (int j = 0; j < p; ++j){
                if (vecp[j].empty()) continue;
                int sizp = vecp[i].size();
                auto& vp = vecp[j];
                int lp = 0, rp = 0;
                while (lp < sizm && rp < sizp){
                    if (vm[lp].first < vp[rp].first) ++lp;
                    else if (vm[lp].first > vp[rp].first) ++rp;
                    else 
                        ans[i][j] += vm[lp].second * vp[rp].second, 
                        ++lp, ++rp;
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
