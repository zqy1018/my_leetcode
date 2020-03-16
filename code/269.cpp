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
    int du[30];
    bool vis[30], mat[30][30];
    string alienOrder(vector<string>& words) {
        int n = words.size(), cnt = 0;
        for (auto& s: words)
            for (char c: s)
                if (!vis[c - 'a'])
                    vis[c - 'a'] = true, ++cnt;                 // 候选
        for (int i = 0; i < n - 1; ++i){
            int l1 = words[i].length(), l2 = words[i + 1].length();
            int l = min(l1, l2);
            bool flag = true;
            for (int j = 0; j < l; ++j){
                if (words[i][j] != words[i + 1][j]){
                    int u = words[i][j] - 'a', v = words[i + 1][j] - 'a';
                    if (!mat[u][v])
                        mat[u][v] = true, ++du[v];
                    flag = false;
                    break;
                }
            }
            if (flag && l1 > l2) return string("");         // 短的排在后面，非法
        }
        queue<int> q;
        for (int i = 0; i < 26; ++i)
            if (vis[i] && !du[i])
                q.push(i);
        string ans;
        while (!q.empty()){
            int h = q.front();
            ans.push_back(h + 'a');
            q.pop();
            for (int i = 0; i < 26; ++i)
                if (mat[h][i]){
                    --du[i];
                    if (!du[i]) q.push(i);
                }
        }
        if (ans.length() < cnt) return string("");          // 拓扑排序失败
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
