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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int d1 = 0, d2 = 0;
        ListNode *t1 = headA, *t2 = headB;
        while(headA != NULL)
            headA = headA->next, d1++;
        while(headB != NULL)
            headB = headB->next, d2++;
        while(d1 < d2) t2 = t2->next, d2--;
        while(d2 < d1) t1 = t1->next, d1--;
        while(d1 && t1 != t2)
            t2 = t2->next, t1 = t1->next, d1--;
        return t1; 
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
