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
    ListNode* partition(ListNode* head, int x) {
        ListNode *hhd1 = new ListNode(-1), *hhd2 = new ListNode(-1);
        ListNode *p = hhd1, *q = hhd2;
        while(head != NULL){
            if(head->val < x) p->next = head, p = p->next;
            else q->next = head, q = q->next;
            head = head->next;
        }
        p->next = hhd2->next, q->next = NULL;
        return hhd1->next;
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
