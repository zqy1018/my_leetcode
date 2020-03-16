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
    unordered_set<string> ans;
    string tmp, ss;
    int ll;
    void dfs(int cur, int l_left, int r_left, int left){
        if (cur == ll){
            if (!l_left && !r_left && !left)
                ans.insert(tmp);
            return ;
        }
        if (ss[cur] == '('){
            // 不选
            if (l_left) dfs(cur + 1, l_left - 1, r_left, left);
            // 选
            tmp.push_back('('), 
            dfs(cur + 1, l_left, r_left, left + 1), 
            tmp.pop_back();
        }else if (ss[cur] == ')'){
            // 不选
            if (r_left) dfs(cur + 1, l_left, r_left - 1, left);
            // 选
            if (left > 0)
                tmp.push_back(')'), 
                dfs(cur + 1, l_left, r_left, left - 1), 
                tmp.pop_back();
        }else 
            tmp.push_back(ss[cur]), 
            dfs(cur + 1, l_left, r_left, left), 
            tmp.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        // 粗去除
        while (!s.empty() && s.back() == '(')
            s.pop_back();
        int l = s.length(), cur = 0;
        while (cur < l && s[cur] == ')')
            ++cur;
        ss = s.substr(cur);
        int left = 0, rt = 0;
        for (char c: ss){
            if (c == '(') ++left;
            else if (c == ')'){
                if (!left) ++rt;
                else --left;
            }
        }
        ll = ss.length();
        dfs(0, left, rt, 0);
        vector<string> real_ans;
        for (auto& s: ans)
            real_ans.push_back(s);
        return real_ans;
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
