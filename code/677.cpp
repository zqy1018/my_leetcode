
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

int trie[100005][26], val[100005], cnt;
bool isend[100005];
int endval[100005];
void Insert(string& s, int v){
    int p = 1, t = 0, l = s.length();
    while (t < l){
        if (!trie[p][s[t] - 'a'])
            trie[p][s[t] - 'a'] = ++cnt;
        p = trie[p][s[t] - 'a'], val[p] += v;
        ++t;
    }
    isend[p] = true, endval[p] = v;
}
int Sum(string& s){
    int p = 1, t = 0, l = s.length();
    while (t < l && p)
        p = trie[p][s[t] - 'a'], ++t;
    return val[p];
}
int Find(string& s){
    int p = 1, t = 0, l = s.length();
    while (t < l && p)
        p = trie[p][s[t] - 'a'], ++t;
    return (p && isend[p]) ? p: -1;
}
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        memset(trie, 0, sizeof(trie));
        memset(val, 0, sizeof(val));
        memset(isend, 0, sizeof(isend));
        memset(endval, 0, sizeof(endval));
        cnt = 1;
    }
    
    void insert(string key, int val) {
        int pos = Find(key);
        if (pos < 0)
            Insert(key, val);
        else if (endval[pos] != val)
            Insert(key, val - endval[pos]), endval[pos] = val;
    }
    
    int sum(string prefix) {
        return Find(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
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
