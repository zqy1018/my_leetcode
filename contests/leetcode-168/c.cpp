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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0, ll = s.length();
        for (int L = minSize; L <= maxSize; ++L){
            unordered_map<string, int> mp;
            int tot[30] = {0}, cnt = 0;
            for (int i = 0; i < L; ++i){
                int t = s[i] - 'a';
                if (tot[t] == 0) ++cnt;
                ++tot[t];
            }
            if (cnt <= maxLetters){
                string ss = s.substr(0, L);
                mp[ss] = 1;
                ans = max(ans, 1);
            }
            for (int i = L; i < ll; ++i){
                int t = s[i - L] - 'a';
                if (tot[t] == 1) --cnt;
                --tot[t];
                t = s[i] - 'a';
                if (tot[t] == 0) ++cnt;
                ++tot[t];
                if (cnt <= maxLetters){
                    string ss = s.substr(i - L + 1, L);
                    if (!mp.count(ss)) mp[ss] = 1, ans = max(ans, 1);
                    else {
                        ++mp[ss], ans = max(ans, mp[ss]);
                    }
                }
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
