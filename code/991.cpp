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
    int brokenCalc(int X, int Y) {
        long long xx = X;
        int ans = 2147483647, t = 1;
        int lst = 2147483647, st = 0;
        for (; ; ){
            if (xx >= Y){
                long long dif = xx - Y, tmp = t;
                int curans = st;
                while (dif > 0)
                    curans += dif / tmp, dif %= tmp, tmp >>= 1;
                if (curans > ans) break;
                ans = curans;
            }
            xx <<= 1, t <<= 1, ++st;
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
