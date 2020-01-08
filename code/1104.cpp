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
    vector<int> pathInZigZagTree(int label) {
        int t = 1, c = 0;
        while ((t << 1) <= label)
            t <<= 1, ++c;
        vector<int> ans;
        stack<int> st;
        int r = ((c & 1) ? 3 * t - 1 - label: label);
        for (int tmp = r, cur = c, curp = t; tmp >= 1; tmp >>= 1, --cur, curp >>= 1){
            if (cur & 1) st.push(3 * curp - 1 - tmp);
            else st.push(tmp);
        }
        while (!st.empty())
            ans.push_back(st.top()), st.pop();
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
