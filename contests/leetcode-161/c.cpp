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

bool vis[100005];
class Solution {
public:
    stack<int> st;
    string minRemoveToMakeValid(string s) {
        int l = s.length();
        string ans("");
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < l; ++i){
            if (s[i] == '('){
                st.push(i);
            }else if (s[i] == ')'){
                if (!st.empty()){
                    int t = st.top();
                    st.pop();
                    vis[t] = vis[i] = true;
                }
            }else {
                vis[i] = true;
            }
        }
        for (int i = 0; i < l; ++i)
            if (vis[i]) ans.push_back(s[i]);
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
