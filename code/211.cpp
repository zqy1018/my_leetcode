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

class WordDictionary {
private:
    struct Node{
        int al[26];
        bool isend;
        Node() {
            memset(al, 0, sizeof(al));
            isend = false;
        }
    };
    vector<Node> trie;
    int cnt;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie.push_back(Node()), trie.push_back(Node());
        cnt = 1;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int rt = 1;
        for (char c: word){
            if(!trie[rt].al[c - 'a'])
                trie.push_back(Node()), 
                trie[rt].al[c - 'a'] = ++cnt;
            rt = trie[rt].al[c - 'a'];
        }
        trie[rt].isend = true;
    }

    bool search_(string& word, int cur, int rt){
        for (; cur < word.length() && rt; ++cur){
            if (word[cur] == '.'){
                bool flag = false;
                for (int i = 0; i < 26; ++i)
                    if (trie[rt].al[i] && search_(word, cur + 1, trie[rt].al[i])){
                        flag = true;
                        break;
                    }
                return flag;
            }else
                rt = trie[rt].al[word[cur] - 'a'];
        }
        if(rt && trie[rt].isend) return true;
        return false; 
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_(word, 0, 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
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
