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
    int perm[15], ord[130], len[15], n, m, l;
    bool ok(vector<string>& words, string& result){
        // test 1
        if (perm[ord[result[0]]] == 0 && l > 1) return false;
        // test 2
        int tl = 0;
        for (int i = 0; i < m; ++i){
            if (len[i] > 1 && perm[ord[words[i][0]]] == 0) return false;
            tl += perm[ord[words[i][len[i] - 1]]];
        }
        // test 3
        if (tl % 10 != perm[ord[result[l - 1]]]) return false;

        int ll = 0, rr = 0;
        for (int i = 0; i < l; ++i)
            rr = rr * 10 + perm[ord[result[i]]];
        for (int i = 0; i < m; ++i){
            int tt = 0;
            for (int j = 0; j < len[i]; ++j)
                tt = tt * 10 + perm[ord[words[i][j]]];
            ll += tt;
            // test 4
            if (ll > rr) return false;
        }
        return ll == rr;
    }
    bool dfs(int cur, int n, int st, vector<string>& words, string& result){
        if (cur == n) {
            do{
                if (ok(words, result)) return true;
            } while (next_permutation(perm, perm + n));
            return false;
        }
        for (int i = st; i <= 10 - n + cur; ++i){
            perm[cur] = i;
            if (dfs(cur + 1, n, i + 1, words, result)) return true;
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        for (auto& x: words)
            for (auto y: x)
                ord[y] = 1;
        for (auto x: result) 
            ord[x] = 1;
        n = 0, m = words.size(), l = result.length();
        for (int i = 0; i < 128; ++i)
            if (ord[i])
                ord[i] = n++;
        for (int i = 0; i < m; ++i)
            len[i] = words[i].length();
        return dfs(0, n, 0, words, result);
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
