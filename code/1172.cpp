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

class DinnerPlates {
private:
    unordered_map<int, vector<int>> st;
    int cap, cnt, cur;
    priority_queue<int, vector<int>, greater<int>> able;
public:
    DinnerPlates(int capacity) {
        cap = capacity, cnt = 1;
        cur = -1;
        st[0] = vector<int>();
        able.push(0);
    }
    
    void push(int val) {
        if (able.empty())
            st[cnt] = vector<int>(), 
            able.push(cnt), cur = cnt, ++cnt;

        int tp = able.top();
        st[tp].push_back(val);
        if (st[tp].size() == cap) able.pop();
    }
    
    int pop() {
        if (cur == -1) return -1;

        int res = st[cur].back();
        if (st[cur].size() == cap) able.push(cur);
        st[cur].pop_back();
        while (cur >= 0 && st[cur].empty())
            --cur;
        return res;
    }
    
    int popAtStack(int index) {
        if (st[index].empty()) return -1;
        
        int res = st[index].back();
        if (st[index].size() == cap) able.push(index);
        st[index].pop_back();
        if (cur == index){
            while (cur >= 0 && st[cur].empty())
                --cur;
        }
        return res;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
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
