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
    ListNode* swapPairs(ListNode* head) {
        ListNode *hhd = new ListNode(-1), *res = hhd;
        hhd->next = head;
        while(hhd->next != NULL){
            if(hhd->next->next == NULL) break;
            ListNode *tmp = hhd->next->next;
            hhd->next->next = tmp->next;
            tmp->next = hhd->next;
            hhd->next = tmp;
            hhd = tmp->next;
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
