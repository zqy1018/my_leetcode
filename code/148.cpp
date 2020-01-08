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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* hhd = new ListNode(-1);
        hhd->next = head;
        int len = 0;
        while (head != NULL)
            head = head->next, ++len;
        for (int i = 2; i < (len << 1); i <<= 1){
            ListNode* tmp = hhd;
            for (int t = 0; t < len; t += i){

                ListNode* mid = tmp;
                for (int j = (i >> 1); j >= 1 && mid->next != NULL; --j) 
                    mid = mid->next;
                if (mid->next == NULL)
                    break;

                ListNode* rend = mid;
                for (int j = (i >> 1); j >= 1 && rend->next != NULL; --j)
                    rend = rend->next;
                rend = rend->next;

                ListNode *lpos = tmp, *rpos = mid;
                int llen = (i >> 1), rlen = min(i >> 1, len - (i >> 1) - t);
                while (llen && rlen){
                    if (rpos->next->val < lpos->next->val){
                        ListNode* targ = rpos->next;
                        rpos->next = targ->next;
                        targ->next = lpos->next;
                        lpos->next = targ;
                        --rlen;
                    }else --llen;
                    lpos = lpos->next;
                }
                while (rlen) rpos = rpos->next, --rlen;

                tmp = rpos;
            }
        }
        return hhd->next;
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
