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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL) return ;
        ListNode *p;
        int n = 0;
        for (p = head; p != NULL; p = p->next, ++n) ;
        p = head;
        for (int i = (n + 1) >> 1; i > 1; --i)
            p = p->next;
        ListNode *q = NULL, *tmp = p->next;
        p->next = NULL, p = tmp;
        while (p != NULL){
            tmp = p->next; 
            p->next = q;
            q = p, p = tmp;
        }
        while (q != NULL){
            p = head->next, tmp = q->next;
            head->next = q, q->next = p;
            head = p, q = tmp;
        }
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
