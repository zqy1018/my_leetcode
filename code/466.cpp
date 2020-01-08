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

int endp[105][32], nxt[105][26];
unsigned cnt[105][32];
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        memset(endp, 0, sizeof(endp));
        memset(cnt, 0, sizeof(cnt));
        memset(nxt, -1, sizeof(nxt));
        int l1 = s1.length(), l2 = s2.length();
        for (int i = 0; i < 26; ++i){
            int pos = -1;
            for (int j = 0; j < l1; ++j)
                if (s1[j] == i + 'a'){
                    pos = j;
                    break ;
                }
            if (pos < 0){
                for (int j = 0; j < l1; ++j)
                    nxt[j][i] = -1;
            }else {
                nxt[pos][i] = pos;
                for (int j = (pos == 0 ? l1 - 1: pos - 1), lst = pos; j != pos; lst = j, j = (j == 0 ? l1 - 1: j - 1)){
                    if (s1[j] == i + 'a') nxt[j][i] = j;
                    else nxt[j][i] = nxt[lst][i];
                }
            }
        }
        for (int i = 0; i < l2; ++i)
            if (nxt[0][s2[i] - 'a'] < 0) 
                return 0;
        for (int i = 0; i < l1; ++i) {
            int cur = i;
            for (int j = 0; j < l2; ++j){
                int nx = nxt[cur][s2[j] - 'a'];
                if (nx < cur) ++cnt[i][0];
                if (nx == l1 - 1) cur = 0, ++cnt[i][0];
                else cur = nx + 1;
            }
            endp[i][0] = cur;
        }
        for (int i = 1; i <= 26; ++i)
            for (int j = 0; j < l1; ++j)
                endp[j][i] = endp[endp[j][i - 1]][i - 1], 
                cnt[j][i] = cnt[j][i - 1] + cnt[endp[j][i - 1]][i - 1];
        int ans = 0, used = 0, cur = 0;
        for (int i = 26; i >= 0; --i)
            if (cnt[cur][i] + used < n1 || (cnt[cur][i] + used == n1 && endp[cur][i] == 0))
                used += cnt[cur][i], cur = endp[cur][i], 
                ans += (1 << i);
        return ans / n2;
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
