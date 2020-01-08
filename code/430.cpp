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

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
class Solution {
public:
    Node* flatt(Node* head){
        Node* tmp = head;
        while (tmp->next != NULL){
            if (tmp->child != NULL){
                Node* tail = flatt(tmp->child);
                Node* tmp_next = tmp->next;
                tmp->next = tmp->child, tmp->child->prev = tmp;
                tail->next = tmp_next, tmp_next->prev = tail;
                tmp->child = NULL;
                tmp = tmp_next;
            }else tmp = tmp->next;
        }
        if (tmp->child != NULL){
            Node* tail = flatt(tmp->child);
            tmp->next = tmp->child, tmp->child->prev = tmp;
            tail->next = tmp->child = NULL;
            tmp = tail;
        }
        return tmp;
    }
    Node* flatten(Node* head) {
        if (head == NULL) return NULL;
        flatt(head);
        return head;
    }
};
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
