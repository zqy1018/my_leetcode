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
    return os;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class NumMatrix {
    vector<vector<int>>& mat;
    vector<vector<int>> bit, tmp;
    int n, m;
    inline int lowbit(int x){
        return x & (-x);
    }
    inline int query(int r, int c){
        if (r < 0 || c < 0) return 0;
        int res = tmp[r][c];
        for (int i = r + 1; i > 0; i -= lowbit(i))
            for (int j = c + 1; j > 0; j -= lowbit(j))
                res += bit[i - 1][j - 1];
        return res;
    }
public:
    NumMatrix(vector<vector<int>>& matrix): mat(matrix) {
        n = matrix.size();
        if (!n) m = 0;
        else m = matrix[0].size();
        bit = vector<vector<int>>(n, vector<int>(m, 0));
        tmp = mat;
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j) 
                tmp[i][j] += tmp[i][j - 1];
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < m; ++j) 
                tmp[i][j] += tmp[i - 1][j];
    }
    
    void update(int row, int col, int val) {
        int delta = val - mat[row][col];
        for (int i = row + 1; i <= n; i += lowbit(i))
            for (int j = col + 1; j <= m; j += lowbit(j))
                bit[i - 1][j - 1] += delta;
        mat[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        ans += query(row2, col2);
        ans -= query(row2, col1 - 1);
        ans -= query(row1 - 1, col2);
        ans += query(row1 - 1, col1 - 1);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
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
