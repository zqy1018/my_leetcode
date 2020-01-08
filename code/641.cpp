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

class MyCircularDeque {
public:
    
    int *que, hd, tl, siz, cap;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        que = new int[k];
        cap = k, siz = 0;
        hd = tl = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (siz == cap) return false;
        int nxt = (hd == 0 ? cap - 1: hd - 1);
        que[nxt] = value, hd = nxt, ++siz;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (siz == cap) return false;
        int nxt = (tl == cap - 1 ? 0: tl + 1);
        que[tl] = value, tl = nxt, ++siz;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (!siz) return false;
        int nxt = (hd == cap - 1 ? 0: hd + 1);
        hd = nxt, --siz;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (!siz) return false;
        int nxt = (tl == 0 ? cap - 1: tl - 1);
        tl = nxt, --siz;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return (!siz ? -1: que[hd]);
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return (!siz ? -1: que[tl == 0 ? cap - 1: tl - 1]);
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return !siz;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return siz == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
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
