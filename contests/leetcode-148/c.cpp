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

class SnapshotArray {
public:
    struct Node{
        int num, lc, rc;
        Node(int n, int l, int r){
            num = n, lc = l, rc = r;
        }
    };
    int siz, S, ver;
    vector<Node> seg;
    vector<int> root;
    void build_tree(int id, int l, int r){
        if(l == r) {
            seg.push_back(Node(0, -1, -1));
            return ;
        }
        int SS = S, mid = (l + r) >> 1;
        seg.push_back(Node(0, S + 1, S + 2));
        S += 2;
        build_tree(SS + 1, l, mid);
        build_tree(SS + 2, mid + 1, r);
    }
    void insert_tr(int &id, int l, int r, int idx, int v){
        seg.push_back(seg[id]), id = ++S;
        if(l == r) {
            seg[id].num = v;
            return ;
        }
        int mid = (l + r) >> 1;
        if(idx <= mid) insert_tr(seg[id].lc, l, mid, idx, v);
        else insert_tr(seg[id].rc, mid + 1, r, idx, v);
    }
    int query(int id, int l, int r, int idx){
        while(l < r){
            int mid = (l + r) >> 1;
            if(idx <= mid) id = seg[id].lc, r = mid;
            else id = seg[id].rc, l = mid + 1;
        }
        return seg[id].num;   
    }
    SnapshotArray(int length) {
        siz = length, S = 0, ver = 0;
        seg.reserve(300000);
        root.reserve(50000);
        root.push_back(++S);
        seg.push_back(Node(-1, -1, -1));    // dummy
        build_tree(1, 1, siz);
    }
    
    void set(int index, int val) {
        insert_tr(root[ver], 1, siz, index + 1, val);
    }
    
    int snap() {
        root.push_back(root.back()), ++ver;
        return ver - 1;
    }
    
    int get(int index, int snap_id) {
        return query(root[snap_id], 1, siz, index + 1);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
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
