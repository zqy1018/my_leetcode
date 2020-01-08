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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* hhd = new ListNode(-1);
        hhd->next = head;
        unordered_map<int, int> mp, mp2;
        mp[0] = 0;
        ListNode *tmp = hhd;
        int sm = 0, len = 0;
        for (; tmp->next != NULL; ++len, tmp = tmp->next){
            sm += tmp->next->val;
            if (mp.count(sm))
                mp2[mp[sm]] = len + 1;
            else mp[sm] = len + 1;
        }
        if (len == 1 && mp2.count(0)) 
            return NULL;
        else if (len == 1) return head;
        tmp = hhd;
        for (int i = 1; tmp->next != NULL; ){
            if (mp2.count(i - 1)){
                int ed = mp2[i - 1];
                while (i <= ed)
                    ++i, tmp->next = tmp->next->next;
                tmp = tmp->next;
            }else ++i, tmp = tmp->next;
        }
        return head;
    }
};
Solution sol;
void init(){
    ListNode* l = new ListNode(1);
    ListNode* tt = sol.removeZeroSumSublists(l);
    cout << tt->next;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
