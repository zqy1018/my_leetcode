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
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *tmp = head;
        while (tmp != NULL){
            Node *n = new Node(tmp->val, tmp->next, NULL);
            tmp->next = n, tmp = n->next;
        }
        tmp = head;
        while (tmp != NULL){
            if (tmp->random != NULL) 
                tmp->next->random = tmp->random->next;
            tmp = tmp->next->next;
        }
        tmp = head;
        Node *ans = head->next;
        while (tmp->next->next != NULL){
            Node *p = tmp->next->next;
            tmp->next->next = p->next;
            tmp->next = p;
            tmp = p;
        }
        tmp->next->next = NULL;
        tmp->next = NULL;
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
