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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        ListNode *tmp = head, *bef;
        int cnt = 0;
        while(tmp != NULL)
            cnt++, tmp = tmp->next;
        int hf = (cnt + 1) >> 1;
        bef = NULL;
        for (int i = 0; i < hf; ++i) {
            tmp = head->next;
            head->next = bef;
            bef = head, head = tmp;
        }
        if(cnt & 1)
            bef = bef->next;
        for (int i = 0; i < (cnt >> 1); ++i){
            if(bef->val != head->val) return false;
            bef = bef->next;
            head = head->next;
        }
        return true;
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
