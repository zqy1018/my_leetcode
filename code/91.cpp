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
    int numDecodings(string s) {
        vector<int> ans(s.length() + 1, 0);
        ans[0] = ans[1] = 1;
        if (s[0] == '0') ans[1] = 0;
        for (int i = 2; i <= s.length(); ++i){
            if (s[i - 1] != '0') ans[i] = ans[i - 1];
            if (s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)
                ans[i] += ans[i - 2];
        }
        return ans[s.length()];
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
