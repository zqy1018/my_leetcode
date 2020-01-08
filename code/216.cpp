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
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs(int cur, int left, int left_sum){
        if (!left){
            if (!left_sum)
                ans.push_back(tmp);
            return ;
        }
        for (int i = cur + 1; i <= 9; ++i)  {
            if (left_sum - i >= 0)
                tmp.push_back(i), dfs(i, left - 1, left_sum - i), 
                tmp.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n < k) return ans;
        for (int i = 1; i <= 9; ++i)   
            if (n - i >= 0) 
                tmp.push_back(i), dfs(i, k - 1, n - i), tmp.pop_back();
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
