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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
}

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int n = M.size();
        if (!n) return 0;
        int m = M[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ){
                int k = j; 
                while (k < m && M[i][j] == M[i][k])
                    ++k;
                if (M[i][j]) ans = max(ans, k - j);
                j = k;
            }
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ){
                int k = j; 
                while (k < m && M[j][i] == M[k][i])
                    ++k;
                if (M[j][i]) ans = max(ans, k - j);
                j = k;
            }
        for (int i = 1 - m; i < n; ++i)
            for (int j = max(0, i); j < n && j - i < m; ){
                int k = j;
                while (k < n && k - i < m && M[j][j - i] == M[k][k - i])
                    ++k;
                if (M[j][j - i]) ans = max(ans, k - j);
                j = k;
            }
        for (int i = 0; i < n + m - 1; ++i)
            for (int j = max(0, i - m + 1); j < n && i - j >= 0; ){
                int k = j;
                while (k < n && i - k >= 0 && M[j][i - j] == M[k][i - k])
                    ++k;
                if (M[j][i - j]) ans = max(ans, k - j);
                j = k;
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
