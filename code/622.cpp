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

class MyCircularQueue {
public:

    int *que, cap, siz, hd, tl;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        que = new int[k];
        cap = k, siz = 0;
        hd = 0, tl = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if ( siz == cap ) return false;
        int nxt = ( tl + 1 == cap ) ? 0: tl + 1;
        que[tl] = value, tl = nxt, ++siz;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if ( !siz ) return false;
        hd = ( hd + 1 == cap ) ? 0: hd + 1, --siz;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if ( !siz ) return -1;
        return que[hd];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if ( !siz ) return -1;
        return que[( tl == 0 ) ? cap - 1: tl - 1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return ( siz == 0 );
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ( siz == cap );
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
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
