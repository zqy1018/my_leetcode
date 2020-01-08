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
    vector<string> ans;
    void dfs(int cur, string str, vector<vector<int>>& e, vector<string>& wordDict){
        if (!cur) {
            str.pop_back();
            ans.push_back(str);
            return ;
        }
        for (int v: e[cur])
            dfs(cur - wordDict[v].length(), wordDict[v] + " " + str, e, wordDict);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int l = s.length(), n = wordDict.size();
        vector<vector<int>> edges(l + 1, vector<int>());
        edges[0].push_back(-1);
        for (int i = 1; i <= l; ++i){
            for (int j = 0; j < n; ++j){
                int l1 = wordDict[j].length();
                if (i >= l1 && s.substr(i - l1, l1) == wordDict[j] && !edges[i - l1].empty()){
                    edges[i].push_back(j);
                }
            }
        }
        dfs(l, "", edges, wordDict);
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
