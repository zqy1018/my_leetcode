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
    vector<int> c[4];
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        for (int i = 0; i < 3; ++i)
            c[i + 1].push_back(-n);
        for (int i = 0; i < n; ++i)
            c[colors[i]].push_back(i);
        for (int i = 0; i < 3; ++i)
            c[i + 1].push_back(n + n);
        vector<int> ans;
        for (vector<int>& q: queries){
            int id = q[0], cc = q[1];
            if (c[cc].size() == 2) ans.push_back(-1);
            else {
                int t1 = *lower_bound(c[cc].begin(), c[cc].end(), id);
                int t2 = *(upper_bound(c[cc].begin(), c[cc].end(), id) - 1);
                ans.push_back(min(abs(t1 - id), abs(t2 - id)));
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
