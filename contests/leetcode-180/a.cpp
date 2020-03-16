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
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int mini = INT_MAX, maxi = INT_MIN;
                for (int u = 0; u < m; ++u)
                    mini = min(mini, matrix[i][u]);
                for (int u = 0; u < n; ++u)
                    maxi = max(maxi, matrix[u][j]);
                if (matrix[i][j] == mini && matrix[i][j] == maxi)
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<vector<int>> mat[[3,7,8],[9,11,13],[15,16,17]];
    cout << sol.luckyNumbers(mat);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
