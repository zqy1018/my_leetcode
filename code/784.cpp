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
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> pos;
        vector<string> ans;
        int n = S.size();
        for (int i = 0; i < S.size(); ++i){
            if (isalpha(S[i])) S[i] = tolower(S[i]), pos.push_back(i);
        }
        int k = pos.size(), upp = (1 << k), old = 0;
        ans.push_back(S);
        for (int i = 1; i < (1 << k); ++i){
            int gray = (i ^ (i >> 1));
            int pp = __builtin_ctz(gray ^ old);
            S[pos[pp]] = (islower(S[pos[pp]]) ? toupper(S[pos[pp]]): tolower(S[pos[pp]]));
            ans.push_back(S);
            old = gray;
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
