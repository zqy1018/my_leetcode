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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<pair<TreeNode*, int>> vec;
public:
    void move(){
        while (!vec.empty()){
            auto p = vec.top();
            vec.pop();
            if (p.second == 0){
                p.second = 1, vec.push(p);
                if ((p.first)->left != NULL) 
                    vec.push(make_pair((p.first)->left, 0));
            }else if (p.second == 1) {
                p.second = 2, vec.push(p);
                break;
            }else if (p.second == 2){
                if ((p.first)->right != NULL) 
                    vec.push(make_pair((p.first)->right, 0));
            }
        }
    }
    BSTIterator(TreeNode* root) {
        if (root != NULL)
            vec.push(make_pair(root, 0));
        move();
    }
    
    /** @return the next smallest number */
    int next() {
        int res = vec.top().first->val;
        move();
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !vec.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
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
