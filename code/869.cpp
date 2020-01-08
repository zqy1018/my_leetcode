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
    bool reorderedPowerOf2(int N) {
        string c = to_string(N);
        sort(c.begin(), c.end());
        for (int i = 1; i < 2000000000; i <<= 1){
            string d = to_string(i);
            if (c.length() > d.length()) continue;
            if (c.length() < d.length()) break;
            sort(d.begin(), d.end());
            if (c == d) return true;
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
