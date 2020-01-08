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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *res = head, *even = head->next;
        int cnt = 0;
        while(head->next != NULL){
            cnt++;
            if(head->next->next == NULL){printf("%d\n", cnt);
                if(!(cnt & 1)) {
                    head->next->next = even;
                }else {
                    head->next = even;
                }
                break;
            }
            ListNode *tmp = head->next;
            head->next = tmp->next;
            head = tmp;
        }
        return res;
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
