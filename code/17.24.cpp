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
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = INT_MIN;
        int xx1, xx2, yy1, yy2;
        for (int j = 0; j < m; ++j) 
            for (int i = 1; i < n; ++i)
                matrix[i][j] += matrix[i - 1][j];
        for (int i = 0; i < n; ++i){
            int mini = 0, minp = 0, sum = 0;
            for (int j = 0; j < m; ++j){
                sum += matrix[i][j];
                if (sum - mini > maxi)
                    maxi = sum - mini, 
                    xx1 = 0, xx2 = i, yy1 = minp, yy2 = j;
                if (sum < mini)
                    mini = sum, minp = j + 1;
            }
        }

        for (int i = 1; i < n; ++i)
            for (int j = i; j < n; ++j){
                int mini = 0, minp = 0, sum = 0;
                for (int k = 0; k < m; ++k){
                    sum += matrix[j][k] - matrix[i - 1][k];
                    if (sum - mini > maxi)
                        maxi = sum - mini, 
                        xx1 = i, xx2 = j, yy1 = minp, yy2 = k;
                    if (sum < mini)
                        mini = sum, minp = k + 1;
                }
            }
        vector<int> ans{xx1, yy1, xx2, yy2};
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
