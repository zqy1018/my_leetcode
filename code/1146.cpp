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

class SnapshotArray {
public:
    vector<map<int, int>> arr;
    int cnt;
    SnapshotArray(int length) {
        cnt = 0;
        for (int i = 0; i < length; ++i)    
            arr.push_back(map<int, int>()), arr[i][0] = 0;
    }
    
    void set(int index, int val) {
        arr[index][cnt] = val;
    }
    
    int snap() {
        int res = cnt++;
        return res;
    }
    
    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id);
        --it;
        return (*it).second;
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
