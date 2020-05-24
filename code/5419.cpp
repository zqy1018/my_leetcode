
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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    int f[505][505];
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i <= n; ++i){
            for (int j = 0; j <= m; ++j)
                f[i][j] = -0x3f3f3f3f;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j){
                f[i][j] = nums1[i - 1] * nums2[j - 1];
                f[i][j] = max(f[i][j], nums1[i - 1] * nums2[j - 1] + f[i - 1][j - 1]);
                f[i][j] = max(f[i][j], f[i - 1][j]);
                f[i][j] = max(f[i][j], f[i][j - 1]);
            }
        return f[n][m];
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
