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
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> f(n + 1, 0x3f3f3f3f);
        f[0] = 0;
        for (int i = 1; i <= n; ++i){
            int sm = books[i - 1][0], maxi = books[i - 1][1];
            for (int j = i - 1; j >= 1 && sm <= shelf_width; --j){
                f[i] = min(f[i], f[j] + maxi);
                maxi = max(maxi, books[j - 1][1]);
                sm += books[j - 1][0];
            }
            if (sm <= shelf_width)
                f[i] = min(f[i], maxi);
        }
        return f[n];
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
