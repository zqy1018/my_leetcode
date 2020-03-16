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
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> vec;
        vector<vector<int>> emp;
        int sm = 0;
        for (auto t: colsum) sm += t;
        if (sm != upper + lower) return emp;
        int n = colsum.size();
        vec = vector<vector<int>>(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2){
                vec[0][i] = vec[1][i] = 1;
                --upper, --lower;
            }
        }
        if (upper < 0 || lower < 0){
            return emp;
        }
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 1){
                if (upper > 0) vec[0][i] = 1, --upper;
                else if (lower > 0) vec[1][i] = 1, --lower;
                else {
                    return emp;
                }
            }
        }
        return vec;
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
