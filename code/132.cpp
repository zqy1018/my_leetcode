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
    vector<vector<int>> pos;
    vector<int> ans;
    int minCut(string s) {
        int n = s.length();
        pos = vector<vector<int> >(n, vector<int>());
        ans = vector<int>(n, n);
        for (int i = 0; i < n; ++i)
            for (int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
                pos[k].push_back(j);
        for (int i = 0; i < n - 1; ++i)
            for (int j = i, k = i + 1; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
                pos[k].push_back(j);
        ans[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j: pos[i]){
                if (j == 0){
                    ans[i] = 0;
                    break;
                }else ans[i] = min(ans[i], ans[j - 1] + 1);
            }
        }
        return ans[n - 1];
    }
};

class Solution {
public:
    vector<vector<int>> pos;
    vector<vector<vector<string> > > ans;
    vector<vector<string>> partition(string s) {
        int n = s.length();
        pos = vector<vector<int> >(n, vector<int>());
        for (int i = 0; i < n; ++i)
            for (int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
                pos[k].push_back(j);
        for (int i = 0; i < n - 1; ++i)
            for (int j = i, k = i + 1; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
                pos[k].push_back(j);
        for (int i = 0; i < n; ++i){
            ans.push_back(vector<vector<string>>());
            for (int hd: pos[i]){
                if (hd == 0){
                    ans[i].push_back(vector<string>{s.substr(0, i + 1)});
                }else {
                    int lst = ans[i].size();
                    for (int j = 0; j < ans[hd - 1].size(); ++j)
                        ans[i].push_back(ans[hd - 1][j]);
                    for (int j = lst; j < ans.back().size(); ++j)
                        ans[i][j].push_back(s.substr(hd, i - hd + 1));
                }
            }
        }
        return ans.back();
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
