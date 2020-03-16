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
    vector<int> nm;
    vector<vector<vector<double>>> vec;
    void dfs(int l, int r){
        if (!vec[l][r].empty()) return ;
        if (l == r){
            vec[l][r].push_back(nm[l]);
            return ;
        }
        for (int i = l; i < r; ++i){
            dfs(l, i), dfs(i + 1, r);
            for (auto x: vec[l][i])
                for (auto y: vec[i + 1][r]){
                    vec[l][r].push_back(x + y);
                    vec[l][r].push_back(x - y);
                    vec[l][r].push_back(x * y);
                    if (fabs(y) > 1e-6) 
                        vec[l][r].push_back(x / y);
                }
        }
    }
    bool judgePoint24(vector<int>& nums) {
        nm = nums;
        sort(nm.begin(), nm.end());
        vec = vector<vector<vector<double>>>(4, vector<vector<double>>(4, vector<double>()));
        do {
            dfs(0, 3);
            for (auto x: vec[0][3])
                if (fabs(x - 24.0) < 1e-6) return true;
            for (auto& v1: vec)
                for (auto& v2: v1)
                    v2.pop_back();
        } while (next_permutation(nm.begin(), nm.end()));
        return false;
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
