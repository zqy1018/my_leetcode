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
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int cnt[12] = {0};
        for (string& str: words){
            char c = 'z' + 1;
            int f = 0;
            for (char t: str){
                if (t < c) c = t, f = 1;
                else if (t == c) ++f;
            }
            ++cnt[f];
        }
        vector<int> ans;
        for (int i = 9; i >= 0; --i)
            cnt[i] += cnt[i + 1];
        for (string& str: queries){
            char c = 'z' + 1;
            int f = 0;
            for (char t: str){
                if (t < c) c = t, f = 1;
                else if (t == c) ++f;
            }
            ans.push_back(cnt[f + 1]);
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
