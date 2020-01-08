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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> vec[26];
        int n = s.length();
        for (int i = 0; i < 26; ++i)
            vec[i].resize(n + 1, 0);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < 26; ++j)
                vec[j][i + 1] = vec[j][i];
            ++vec[s[i] - 'a'][i + 1];
        }
        for (vector<int>& q: queries){
            int l = q[0], r = q[1], k = q[2];
            int cnt = 0;
            for (int i = 0; i < 26; ++i)    
                cnt += ((vec[i][r + 1] - vec[i][l]) & 1);
            ans.push_back(cnt - 1 <= k); 
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
