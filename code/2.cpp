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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1), *p = head;
        int x = 0;
        while(l1 != NULL && l2 != NULL){
            x += l1->val, l1 = l1->next;
            x += l2->val, l2 = l2->next;
            p->next = new ListNode(x % 10);
            x /= 10, p = p->next;
        }
        while(l1 != NULL)
            x += l1->val, l1 = l1->next, p->next = new ListNode(x % 10), x /= 10, p = p->next;
        while(l2 != NULL)
            x += l2->val, l2 = l2->next, p->next = new ListNode(x % 10), x /= 10, p = p->next;
        if(x) p->next = new ListNode(x), p = p->next;
        return head->next;
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
