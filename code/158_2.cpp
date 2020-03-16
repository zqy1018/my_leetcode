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

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int q[5], hd, tl;
    int read(char *buf, int n) {
        int tot = 0;
        while (hd < tl && tot < n){
            *buf = q[hd++];
            ++tot, ++buf;
        }
        if (tot == n) return tot;
        while (tot + 4 <= n){
            int res = read4(buf);
            tot += res;
            if (res < 4) return tot;
            buf += 4;
        }
        if (tot == n) return tot;
        char tmp[4];
        int res = read4(tmp);
        hd = tl = 0;
        for (int i = 0; i < res; ++i)
            q[tl++] = tmp[i];
        while (hd < tl && tot < n){
            *buf = q[hd++];
            ++tot, ++buf;
        }
        return tot;
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
