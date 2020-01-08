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
        ListNode *tmp1 = l1, *tmp2 = l2;
        ListNode *lst = NULL;
        int n1 = 0, n2 = 0;
        while(tmp1 != NULL)
            tmp1 = tmp1->next, n1++;
        while(tmp2 != NULL)
            tmp2 = tmp2->next, n2++;
        int n = max(n1, n2);
        tmp1 = tmp2 = NULL;
        for (int i = 0; i < n; ++i){
            if(n - i == n1) tmp1 = l1;
            if(n - i == n2) tmp2 = l2;
            int x = 0;
            if(n - i <= n1) x += tmp1->val, tmp1 = tmp1->next;  
            if(n - i <= n2) x += tmp2->val, tmp2 = tmp2->next;
            ListNode *aans = new ListNode(x);
            aans->next = lst, lst = aans;
        }
        for (tmp1 = lst, tmp2 = NULL; tmp1 != NULL; tmp1 = tmp1->next){
            if(tmp1->val >= 10){
                if(tmp1->next == NULL)
                    tmp1->next = new ListNode(1);
                else
                    tmp1->next->val++;
                tmp1->val %= 10;
            }
        }
        tmp1 = lst;
        while(tmp1 != NULL){
            ListNode *tmp3 = tmp1->next;
            tmp1->next = tmp2;
            tmp2 = tmp1, tmp1 = tmp3;
        }
        return tmp2;
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
