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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *hhd = new ListNode(-1), *tmp;
        hhd->next = head, tmp = head;
        while (tmp->next != NULL){
            int v = tmp->next->val;
            ListNode *p = hhd, *q, *r;
            while (p != tmp){
                if(p->next->val >= v) break;
                p = p->next;
            }
            if (p != tmp) 
                q = p->next, r = tmp->next->next, 
                p->next = tmp->next, tmp->next->next = q, 
                tmp->next = r;
            else tmp = tmp->next;
        }
        return hhd->next;
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
