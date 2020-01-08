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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int v: asteroids){
            if (v < 0){
                while (!s.empty() && s.top() > 0 && -v > s.top())
                    s.pop();
                if (!s.empty()){
                    if (-v == s.top()) s.pop();
                    else if (s.top() < 0) s.push(v);
                }else s.push(v);
            }else {
                s.push(v);
            }
        }
        vector<int> ans;
        int siz = s.size();
        ans.resize(siz);
        for (int i = 0; i < siz; ++i)
            ans[siz - i - 1] = s.top(), s.pop();
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
