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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode *tmp = head, *bef;
        int cnt = 0;
        while(tmp != NULL)
            cnt++, bef = tmp, tmp = tmp->next;
        tmp = head, k %= cnt;
        if(k){
            k = cnt - k;
            int cur = 0;
            for(; ; ){
                cur++;
                if(cur == k) break;
                tmp = tmp->next;
            }
            bef->next = head, head = tmp->next, tmp->next = NULL;
        }
        return head;
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
