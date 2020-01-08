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
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        int cnt[26] = {0}, cnt2[26] = {0};
        int an = A.size(), bn = B.size();
        for (int i = 0; i < bn; ++i){
            for (char c: B[i])
                ++cnt2[c - 'a'];
            for (char c: B[i]){
                cnt[c - 'a'] = max(cnt[c - 'a'], cnt2[c - 'a']);
                --cnt2[c - 'a'];
            }
        }
        for (int i = 0; i < an; ++i){
            for (char c: A[i])
                ++cnt2[c - 'a'];
            bool flag = true;
            for (int j = 0; j < 26; ++j){
                if (cnt2[j] < cnt[j])
                    flag = false;
                cnt2[j] = 0;
            }
            if (flag) ans.push_back(A[i]);
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
