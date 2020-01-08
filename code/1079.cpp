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
    int sel[10], cnt, ans, fac[10];
    void dfs(int choice[], int tot, int left){
        if (!left){
            int res = 1;
            res *= fac[cnt];
            for (int i = 0; i < tot; ++i) res /= fac[sel[i]];
            ans += res;
            return ;
        }
        for (int i = 0; i <= choice[tot - left]; ++i)
            sel[tot - left] = i, cnt += i, dfs(choice, tot, left - 1), cnt -= i;
    }
    int numTilePossibilities(string tiles) {
        cnt = ans = 0;
        sort(tiles.begin(), tiles.end());
        int l = tiles.length();
        int sel_[10], cnt_ = 0;
        fac[0] = 1;
        for (int i = 1; i <= 7; ++i)    
            fac[i] = fac[i - 1] * i;
        for (int i = 0; i < l; ){
            int j = i;
            while (j < l && tiles[i] == tiles[j])
                ++j;
            sel_[cnt_++] = j - i;
            i = j;
        }
        dfs(sel_, cnt_, cnt_);
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
