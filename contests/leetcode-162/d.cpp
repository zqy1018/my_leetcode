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

int cnt[100], cnt2[100];
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        memset(cnt, 0, sizeof(cnt)) ;
        for (char c: letters) ++cnt[c - 'a'];
        int lim = (1 << n);
        int ans = 0;
        for (int i = 0; i < lim; ++i){
            for (int j = 0; j < 26; ++j)
                cnt2[j]  = 0;
            for (int j = 1, t = 0; t < n; ++t, j <<= 1){
                if (!(j & i)) continue;
                for (char cc: words[t])
                    ++cnt2[cc - 'a'];
            }
            bool flag = true;
            int tot = 0;
            for (int j = 0; j < 26; ++j){
                if (cnt2[j] > cnt[j]){
                    flag = false;
                    break;
                }
                tot += cnt2[j] * score[j];
            }
            if (flag) ans = max(ans, tot);
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
