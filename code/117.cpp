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
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
class Solution {
public:
    void ct(Node* root) {
        if(root == NULL) return ;
        if(root->left != NULL && root->right == NULL){
            Node *tmp = root->next;
            while(tmp != NULL && tmp->left == NULL && tmp->right == NULL)
                tmp = tmp->next;
            if(tmp == NULL) root->left->next = NULL;
            else {
                if(tmp->left != NULL)
                    root->left->next = tmp->left;
                else
                    root->left->next = tmp->right;
            }
        }else if(root->right != NULL){
            if(root->left != NULL)
                root->left->next = root->right;
            Node *tmp = root->next;
            while(tmp != NULL && tmp->left == NULL && tmp->right == NULL)
                tmp = tmp->next;
            if(tmp == NULL) root->right->next = NULL;
            else {
                if(tmp->left != NULL)
                    root->right->next = tmp->left;
                else
                    root->right->next = tmp->right;
            }
        }
        ct(root->right), ct(root->left);
    }
    Node* connect(Node* root) {
        ct(root);
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
