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

class WordFilter {
    int id[20005], id_rev[20005];
    int trie[20005][26], trie_rev[20005][26];
    int n, ans;
    unordered_set<int> st;
    void dfs(int cur){
        if (id[cur] >= 0) st.insert(id[cur]);
        for (int i = 0; i < 26; ++i)
            if (trie[cur][i] > 0) dfs(trie[cur][i]);
    }
    void dfs2(int cur){
        if (id_rev[cur] >= 0 && st.count(id_rev[cur])) 
            ans = max(ans, id_rev[cur]);
        for (int i = 0; i < 26; ++i)
            if (trie_rev[cur][i] > 0) dfs2(trie_rev[cur][i]);
    }
public:
    WordFilter(vector<string>& words) {
        n = words.size();
        memset(id, -1, sizeof(id));
        memset(id_rev, -1, sizeof(id_rev));
        memset(trie, 0, sizeof(trie));
        memset(trie_rev, 0, sizeof(trie_rev));
        int cnt = 1, cnt_rev = 1;
        for (int i = 0; i < n; ++i){
            auto& s = words[i];
            int p = 1, l = s.length();
            for (char c: s){
                if (!trie[p][c - 'a'])
                    trie[p][c - 'a'] = ++cnt;
                p = trie[p][c - 'a'];
            }
            id[p] = max(id[p], i);
            p = 1;
            for (int i = l - 1; i >= 0; --i){
                if (!trie_rev[p][s[i] - 'a'])
                    trie_rev[p][s[i] - 'a'] = ++cnt_rev;
                p = trie_rev[p][s[i] - 'a'];
            }
            id_rev[p] = max(id_rev[p], i);
        }
    }
    
    int f(string prefix, string suffix) {
        st.clear();
        int p = 1, lp = prefix.length(), ls = suffix.length();
        for (int i = 0; i < lp && p; ++i)
            p = trie[p][prefix[i] - 'a'];
        if (!p) return -1;
        dfs(p);
        ans = -1, p = 1;
        for (int i = ls - 1; i >= 0 && p; --i)
            p = trie_rev[p][suffix[i] - 'a'];
        if (!p) return -1;
        dfs2(p);
        return ans;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
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
