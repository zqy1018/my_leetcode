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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *hhd = new ListNode(-1), *res = hhd;
        hhd->next = head;
        while(hhd->next != NULL){
            ListNode *tmp = hhd->next;
            while(tmp != NULL && tmp->val == hhd->next->val)
                tmp = tmp->next;
            if(hhd->next->next != tmp)
                hhd->next = tmp;
            else hhd = hhd->next;
        }
        return res->next;
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
