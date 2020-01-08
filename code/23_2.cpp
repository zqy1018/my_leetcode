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

template <typename T>
struct Heap{
    T* h;
    int siz;
    Heap(int _siz){
        h = new T[_siz + 1];
        siz = 0;
    }

    ~Heap(){
        delete [] h;
    }

    void up(int x){
        T tmp = h[x];
        while (x > 1){
            int fa = x >> 1;
            if (h[fa]->val < tmp->val) break;
            h[x] = h[fa], x = fa;
        }
        h[x] = tmp;
    }

    void down(int x){
        T tmp = h[x];
        while ((x << 1) <= siz){
            int ch = (x << 1);
            if (ch + 1 <= siz && h[ch + 1]->val < h[ch]->val)
                ++ch;
            if (tmp->val < h[ch]->val) break;
            h[x] = h[ch], x = ch;
        }
        h[x] = tmp;
    }

    void heapify(){
        for (int i = siz >> 1; i >= 1; --i)
            down(i);
    }

    void push(const T& x){
        h[++siz] = x;
        up(siz);
    }

    T pop(){
        T res = h[1];
        swap(h[1], h[siz--]);
        down(1);
        return res;
    }

    T top(){
        return h[1];
    }

    bool empty(){
        return siz == 0;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        Heap<ListNode*> pq(k);
        ListNode *dummy_head = new ListNode(-1);
        ListNode *tail = dummy_head;
        for (int i = 0; i < k; ++i)
            if (lists[i] != NULL)
                pq.push(lists[i]);
        while (!pq.empty()){
            ListNode *cur_node = pq.pop();
            tail->next = cur_node, tail = tail->next;
            cur_node = cur_node->next;
            if (cur_node != NULL)
                pq.push(cur_node); 
        }
        return dummy_head->next;
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

