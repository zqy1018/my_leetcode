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
    bool vis[505];
    string boldWords(vector<string>& words, string S) {
        int l = S.length();
        for (auto& w: words){
            int cur = 0, ll = w.length();
            for (; ; ){
                int t = S.find(w, cur);
                if (t == -1) break;
                for (int i = 0; i < ll; ++i)
                    vis[t + i] = true;
                cur = t + 1;
            }
        }
        string ans;
        for (int i = 0; i < l; ){
            if (!vis[i])
                ans.push_back(S[i]), ++i;
            else{
                int j = i;
                ans += "<b>";
                while (j < l && vis[j])
                    ans.push_back(S[j]), ++j;
                ans += "</b>";
                i = j;
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
