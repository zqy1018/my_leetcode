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
    string complexNumberMultiply(string a, string b) {
        int xa = 0, xb = 0, xc = 0, xd = 0, flag = 1;
        int i = 0;

        if ( a[i] == '-' ) flag = -1, ++i;
        for (; a[i] != '+'; ++i)
            xa = xa * 10 + a[i] - '0';
        xa *= flag, flag = 1, ++i;
        if ( a[i] == '-' ) flag = -1, ++i;
        for (; a[i] != 'i'; ++i)
            xb = xb * 10 + a[i] - '0';
        xb *= flag, flag = 1, i = 0;

        if ( b[i] == '-' ) flag = -1, ++i;
        for (; b[i] != '+'; ++i)
            xc = xc * 10 + b[i] - '0';
        xc *= flag, flag = 1, ++i;
        if ( b[i] == '-' ) flag = -1, ++i;
        for (; b[i] != 'i'; ++i)
            xd = xd * 10 + b[i] - '0';
        xd *= flag, flag = 1;

        return to_string( xa * xc - xb * xd ) + string("+") + to_string( xa * xd + xb * xc ) + string("i");
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
