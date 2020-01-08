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
    string getHint(string secret, string guess) {
        int cnt[10] = {0}, c1 = 0, c2 = 0;
        for (int i = 0; i < secret.length(); ++i)
            if ( secret[i] == guess[i] ) ++c1;
            else ++cnt[secret[i] - '0'];
        for (int i = 0; i < guess.length(); ++i)
            if ( secret[i] != guess[i] && cnt[guess[i] - '0'] ) ++c2, --cnt[guess[i] - '0'];
        return to_string(c1) + "A" + to_string(c2) + "B";
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
