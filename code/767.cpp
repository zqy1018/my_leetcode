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
    string reorganizeString(string S) {
        int cnt[26] = {0}, l = S.length();
        for (char c: S) ++cnt[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (cnt[i] > (l + 1) >> 1)
                return string();
        vector<pair<int, int>> vec;
        for (int i = 0; i < 26; ++i)
            if (cnt[i]) vec.push_back(make_pair(-cnt[i], i));
        sort(vec.begin(), vec.end());
        string ans = S;
        int cur = 0;
        for (auto& p: vec){
            for (int i = 0; i < p.first; ++i){
                ans[cur] = p.second + 'a';
                cur += 2;
                if (cur >= l) cur = 1;
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
