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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(head == NULL) return vector<int>();
        ListNode *p = head, *q = head->next, *tmp = NULL;
        int n = 0;
        for(; ; ){
            p->next = tmp, tmp = p, ++n;
            if(q == NULL) break;
            p = q, q = q->next;
        }
        head = p;
        stack<int> st;
        vector<int> ans(n, 0);
        while(head->next != NULL){
            while(!st.empty() && head->val >= st.top())
                st.pop();
            --n;
            if(!st.empty()) ans[n] = st.top();
            st.push(head->val);
            head = head->next;
        }
        return ans;
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
