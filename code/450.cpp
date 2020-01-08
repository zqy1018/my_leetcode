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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val < key) 
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else{
            if (root->left && root->right){
                TreeNode* t = root->right;
                while (t->left != NULL)
                    t = t->left;
                swap(root->val, t->val);
                root->right = deleteNode(root->right, t->val);
            }else{
                if (root->left) return root->left;
                if (root->right) return root->right;
                return NULL;
            }
        }
        return root;
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
