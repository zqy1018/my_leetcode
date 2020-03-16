

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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class MaxQueue {
    int hd, tl;
    deque<pair<int, int> > q1;
    queue<int> q2;
public:
    MaxQueue() {
        hd = tl = 0;
    }
    
    int max_value() {
        if (q2.empty()) return -1;
        return q1.front().second;
    }
    
    void push_back(int value) {
        while (!q1.empty() && q1.back().second <= value)
            q1.pop_back();
        q1.push_back(make_pair(tl, value));
        q2.push(value);
        ++tl;
    }
    
    int pop_front() {
        if (q2.empty()) return -1;
        int res = q2.front();
        if (q1.front().first == hd) q1.pop_front();
        q2.pop(), ++hd;
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
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
