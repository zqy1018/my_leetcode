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
    int sum[155][155];
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i + 1][j] + mat[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] += sum[i][j + 1];
        int ans = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                for (int h = 1; h <= i; ++h){
                    int wl = 0, wr = j;
                    while (wr > wl){
                        int wmid = (wl + wr + 1) >> 1;
                        if (sum[i][j] - sum[i - h][j] - sum[i][j - wmid] + sum[i - h][j - wmid] == 
                            h * wmid)
                            wl = wmid;
                        else wr = wmid - 1;
                    }
                    ans += wl;
                }
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
