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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *res = head, *bef = NULL;
        int cnt = 0;
        ListNode *mq = NULL, *mm, *nn, *nh;
        while(head != NULL){
            cnt++;
            if(cnt == m - 1) mq = head;
            if(cnt == m) mm = head;
            if(cnt > m){
                ListNode *tmp = head->next;
                head->next = bef;
                bef = head, head = tmp;
            }else{
                bef = head, head = head->next;
            }
            if(cnt == n) {
                nn = bef, nh = head;
                head = bef;
                if(mq != NULL) mq->next = head;
                mm->next = nh;
                break;
            }
        }
        if(mq == NULL) return nn;
        else return res;
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
