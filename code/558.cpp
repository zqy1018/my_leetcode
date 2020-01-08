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

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution {
public:
    bool dfs2(Node* t){
        if (t->isLeaf) return t->val;
        return dfs2(t->topLeft) || dfs2(t->topRight) || dfs2(t->bottomLeft) || dfs2(t->bottomRight);
    }
    void dfs(Node* t1, Node* t2){
        if (t1->isLeaf) {
            t1->val = t1->val || dfs2(t2);
            return ;
        }
        if (t2->isLeaf) {
            t1->val = dfs2(t1) || t2->val;
            t1->topLeft = t1->topRight = t1->bottomLeft = t1->bottomRight = NULL;
            t1->isLeaf = true;
            return ;
        }
        dfs(t1->topLeft, t2->topLeft); 
        dfs(t1->topRight, t2->topRight); 
        dfs(t1->bottomLeft, t2->bottomLeft); 
        dfs(t1->bottomRight, t2->bottomRight); 
        if (t1->topLeft->isLeaf && t1->topRight->isLeaf && t1->bottomLeft->isLeaf && t1->bottomRight->isLeaf
            && t1->topLeft->val == t1->topRight->val 
            && t1->topLeft->val == t1->bottomRight->val
            && t1->topLeft->val == t1->bottomLeft->val)
            t1->isLeaf = true, t1->val = t1->topLeft->val, 
            t1->topLeft = t1->topRight = t1->bottomLeft = t1->bottomRight = NULL;
    }
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1 == NULL || quadTree2 == NULL)
            return NULL;
        dfs(quadTree1, quadTree2);
        return quadTree1;
    }
};
/*
{"$id":"1","bottomLeft":{"$id":"4","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":false},"bottomRight":{"$id":"5","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":false},"isLeaf":false,"topLeft":{"$id":"2","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":true},"topRight":{"$id":"3","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":true},"val":true}
{"$id":"1","bottomLeft":{"$id":"8","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":true},"bottomRight":{"$id":"9","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":false},"isLeaf":false,"topLeft":{"$id":"2","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":true},"topRight":{"$id":"3","bottomLeft":{"$id":"6","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":true},"bottomRight":{"$id":"7","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":true},"isLeaf":false,"topLeft":{"$id":"4","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":false},"topRight":{"$id":"5","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":false},"val":true},"val":true}
{"$id":"1","bottomLeft":{"$id":"4","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":false},"bottomRight":{"$id":"5","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":false},"isLeaf":false,"topLeft":{"$id":"2","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":true},"topRight":{"$id":"3","bottomLeft":null,"bottomRight":null,"isLeaf":true,"topLeft":null,"topRight":null,"val":true},"val":true}
*/
void init(){
    
}
void solve(){
    // sol.convert();
}
int main(){
    int T = read();
    while (T--){
 init();
    solve();
    }
    return 0;
}
