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
    bool rotateString(string A, string B) {
        if ( A == B ) return true;
        int n = A.size();
        for (int i = 1; i < n; ++i){
            bool flag = true;
            for (int j = 0; j < i; ++j)
                if ( A[j] != B[n - i + j] ) {
                    flag = false;
                    break;
                }
            if ( !flag ) continue;
            for (int j = i; j < n; ++j)
                if ( A[j] != B[j - i] ) {
                    flag = false;
                    break;
                }
            if ( flag ) return true;
        }  
        return false;
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
