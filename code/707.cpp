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

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    ListNode *hhd, *tmp, *tl;
    int len;
    MyLinkedList() {
        hhd = new ListNode(-1);
        tl = hhd;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= len || index < 0) return -1;
        if (index == len - 1)
            return tl->val;
        tmp = hhd;
        for (int i = 0; i < index; ++i) 
            tmp = tmp->next;
        return tmp->next->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* n = new ListNode(val);
        n->next = hhd->next, hhd->next = n;
        ++len;
        if (len == 1) tl = n;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* n = new ListNode(val);
        tl->next = n, tl = n;
        ++len;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == len) addAtTail(val);
        else if (index < 0) addAtHead(val);
        else if (index > len) return ;
        else{
            tmp = hhd;
            for (int i = 0; i < index; ++i) 
                tmp = tmp->next;
            ListNode* n = new ListNode(val);
            n->next = tmp->next, tmp->next = n;
            ++len;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= len || index < 0) return ;
        tmp = hhd;
        for (int i = 0; i < index; ++i) 
            tmp = tmp->next;
        tmp->next = tmp->next->next;
        if (index == len - 1) tl = tmp;
        --len;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
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
