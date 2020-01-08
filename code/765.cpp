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
    int minSwapsCouples(vector<int>& row) {
        int to[31][2], ans = 0, n = row.size();
        int f = 0;
        memset(to, -1, sizeof(to));
        for (int i = 0; i < n; i += 2){
            int t1 = row[i] >> 1, t2 = row[i + 1] >> 1;
            if (to[t1][0] < 0) to[t1][0] = t2;
            else to[t1][1] = t2;
            if (to[t2][0] < 0) to[t2][0] = t1;
            else to[t2][1] = t1;
        }
        for (int i = (n >> 1) - 1; i >= 0; --i){
            if (f & (1 << i)) continue;
            int cnt = 0, t = i, fa = -1;
            do{
                f |= (1 << t);
                int tt = (to[t][0] == fa ? to[t][1]: to[t][0]);
                fa = t, t = tt, ++cnt;
            }while (t != i);
            ans += cnt - 1;
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
