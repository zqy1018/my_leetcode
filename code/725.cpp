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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k, NULL);
        ListNode *tmp = root;
        int n = 0;
        while(tmp != NULL) tmp = tmp->next, ++n;
        int l = n / k, res = n % k;
        tmp = root;
        for (int i = 0; i < k && tmp != NULL; ++i){
            ListNode *curroot = tmp;
            for (int j = (res ? --res, 1: 0) + l; j > 1; --j)
                tmp = tmp->next;
            ans[i] = curroot;
            curroot = tmp->next, tmp->next = NULL, tmp = curroot;
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
