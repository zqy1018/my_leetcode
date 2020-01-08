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

int trie[100005][26], cnt;
int pos[26], tot;
bool isend[100005];
void insert(string& s){
    int p = 1, t = 0, l = s.length();
    while (t < l){
        if (!trie[p][s[t] - 'a'])
            trie[p][s[t] - 'a'] = ++cnt;
        p = trie[p][s[t] - 'a'];
        ++t;
    }
    isend[p] = true;
}
bool Find(string& s, int root, int st){
    int p = root, t = st, l = s.length();
    while (t < l && p)
        p = trie[p][s[t] - 'a'], ++t;
    return p && isend[p];
}
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        memset(trie, 0, sizeof(trie));
        memset(isend, 0, sizeof(isend));
        cnt = 1;
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string& s: dict)
            insert(s);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int p = 1, t = 0, l = word.length();
        while (t < l && p){
            tot = 0;
            for (int i = 0; i < 26; ++i)    
                if (trie[p][i] && i + 'a' != word[t]) pos[tot++] = trie[p][i];
            for (int i = 0; i < tot; ++i)   
                if (Find(word, pos[i], t + 1)) 
                    return true;
            p = trie[p][word[t] - 'a'], ++t;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
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
