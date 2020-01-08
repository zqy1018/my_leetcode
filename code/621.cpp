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
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for (char c: tasks) ++cnt[c - 'A'];
        int ans = 0;
        ++n;
        if (n >= 26) {
            int maxi = 0, tot = 0;
            for (int i = 0; i < 26; ++i)    
                if (cnt[i] > maxi)
                    maxi = cnt[i], tot = 1;
                else if (cnt[i] == maxi) ++tot;
            ans = (maxi - 1) * n + tot;
        }else {
            int pos[26] = {0};
            pair<int, int> pp[26];
            int vcnt = 0;
            for (int i = 0; i < 26; ++i)
                if (cnt[i])
                    pp[vcnt].first = -cnt[i], pp[vcnt].second = i, ++vcnt;
            sort(pp, pp + vcnt);
            int cur = min(n, vcnt), tot = tasks.size();
            for (int i = 0; i < cur; ++i)
                pos[i] = pp[i].second;
            for (int i = 0; tot > 0; i = (i + 1 == n ? 0: i + 1)){
                if (cnt[pos[i]] == 0) {
                    ++ans;
                    continue;
                }
                --cnt[pos[i]], --tot;
                if (cnt[pos[i]] == 0 && cur < vcnt)
                    pos[i] = pp[cur].second, ++cur;
                ++ans;
            }
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
