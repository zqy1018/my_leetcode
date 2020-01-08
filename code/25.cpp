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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *hhd = new ListNode(-1), *res = hhd;
        hhd->next = head;
        while(hhd->next != NULL){
            int cnt = 0;
            ListNode *tt;
            for (tt = hhd; tt->next != NULL && cnt < k; tt = tt->next)
                ++cnt;
            if(cnt < k) break;
            ListNode *bef = hhd, *cur = hhd->next, *tmp, *tmp2 = tt->next;
            for (int i = 0; i < k; ++i){
                tmp = cur->next;
                cur->next = bef;
                bef = cur, cur = tmp;
            }
            hhd->next->next = tmp2;
            tmp2 = hhd->next;
            hhd->next = tt;
            hhd = tmp2; 
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
