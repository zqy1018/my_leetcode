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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct P{
            int val, id;
            P(int v, int i): val(v), id(i) {}
        };
        struct cmp{
            bool operator ()(const P &p1, const P &p2){
                return p1.val > p2.val;
            }
        };
        priority_queue<P, vector<P>, cmp> pq;
        ListNode *head = new ListNode(0), *res = head;
        int n = lists.size();
        for (int i = 0; i < n; ++i)
            if(lists[i] != NULL)
                pq.push(P(lists[i]->val, i));
        while(!pq.empty()){
            P t = pq.top();
            pq.pop();
            head->next = lists[t.id], head = head->next;
            lists[t.id] = lists[t.id]->next;
            if(lists[t.id] != NULL)
                pq.push(P(lists[t.id]->val, t.id)); 
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
