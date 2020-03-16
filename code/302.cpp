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
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size(), m = image[0].size();
        int xx1 = n, xx2 = -1, yy1 = m, yy2 = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (image[i][j] == '1')
                    xx1 = min(xx1, i), 
                    xx2 = max(xx2, i), 
                    yy1 = min(yy1, j), 
                    yy2 = max(yy2, j);
        return (yy2 - yy1 + 1) * (xx2 - xx1 + 1);
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
