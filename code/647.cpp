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
    int countSubstrings(string s) {
        int ans = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            for (int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
                ++ans;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i, k = i + 1; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
                ++ans;
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
