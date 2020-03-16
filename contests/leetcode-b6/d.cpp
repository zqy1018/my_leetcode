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
    bool canConvert(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();
        vector<int> mp(26, -1);
        for (int i = 0; i < l1; ){
            int j = i, j2 = i;
            while (j < l1 && str1[i] == str1[j]) ++j;
            while (j2 < l2 && str2[i] == str2[j2]) ++j2;
            if (j2 < j) return false;
            if (mp[str1[i] - 'a'] < 0) mp[str1[i] - 'a'] = str2[i] - 'a';
            else {
                if (mp[str1[i] - 'a'] != str2[i] - 'a')
                    return false;
            }
            i = j;
        }
        int occ = 0, cnt = 26;
        int deg[26] = {0};
        bool vis[26] = {0};
        for (int i = 0; i < 26; ++i){
            if (mp[i] < 0) ++occ;
            else if (mp[i] == i) mp[i] = -1;
            else ++deg[mp[i]];
        }
        for (int i = 0; i < 26; ++i){
            if (deg[i]) continue;
            int tp = i;
            --cnt, vis[tp] = true;
            while (mp[tp] >= 0){
                if (vis[mp[tp]]) break;
                --cnt, vis[mp[tp]] = true, tp = mp[tp];
            }
        }
        return occ || cnt == 0;
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
