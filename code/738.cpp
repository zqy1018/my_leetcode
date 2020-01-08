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
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int n = s.length();
        if (n == 1) return N;
        int lsth = 0, lstt = 0;
        while (lstt < n && s[lsth] == s[lstt])
            ++lstt;
        if (lstt == n) return N;
        for (int i = lstt; i < n; ){
            int j = i;
            while (j < n && s[j] == s[i])
                ++j;
            if (s[i] < s[lsth]){
                if (s[lsth] == '1'){
                    int x = 0;
                    for (int i = 0; i < n - 1; ++i)
                        x = x * 10 + 9;
                    return x;
                }else {
                    --s[lsth];
                    for (int t = lsth + 1; t < n; ++t)
                        s[t] = '9';
                    break;
                }
            }
            lsth = i, lstt = j, i = j;
        }
        int x = 0;
        for (int i = 0; i < n; ++i) 
            x = x * 10 + s[i] - '0';
        return x;
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
