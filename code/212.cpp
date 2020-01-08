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

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
class WordDictionary {
public:
    struct Node{
        int al[26], isend;
        Node() {
            memset(al, 0, sizeof(al));
            isend = 0;
        }
    };
    vector<Node> trie;
    int cnt;
    WordDictionary() {
        trie.push_back(Node()), trie.push_back(Node());
        cnt = 1;
    }
    void addWord(string& word, int iid) {
        int rt = 1;
        for (char c: word){
            if(!trie[rt].al[c - 'a'])
                trie.push_back(Node()), 
                trie[rt].al[c - 'a'] = ++cnt;
            rt = trie[rt].al[c - 'a'];
        }
        trie[rt].isend = iid;
    }
};
class Solution {
public:
    WordDictionary wc;
    int n, m;
    vector<vector<bool> > vis;
    vector<bool> stat;
    void dfs(vector<vector<char>>& board, int x, int y, int rt){
        if (wc.trie[rt].isend > 0) 
            stat[wc.trie[rt].isend - 1] = true;
        for (int i = 0; i < 4; ++i){
            int cx = x + dx[i], cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || vis[cx][cy]) continue;
            if (!wc.trie[rt].al[board[cx][cy] - 'a']) continue;
            int new_rt = wc.trie[rt].al[board[cx][cy] - 'a'];
            vis[cx][cy] = true;
            dfs(board, cx, cy, new_rt);
            vis[cx][cy] = false;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.empty()) return ans;
        if (words.empty()) return ans;
        n = board.size(), m = board[0].size();
        vis = vector<vector<bool> >(n, vector<bool>(m, false));
        int wz = words.size();
        stat = vector<bool>(wz, false);
        for (int i = 0; i < wz; ++i)
            wc.addWord(words[i], i + 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (!wc.trie[1].al[board[i][j] - 'a']) continue;
                int new_rt = wc.trie[1].al[board[i][j] - 'a'];
                vis[i][j] = true, dfs(board, i, j, new_rt), vis[i][j] = false;
            }
        for (int i = 0; i < wz; ++i)
            if (stat[i]) ans.push_back(words[i]);
        return ans;
    }
};
Solution sol;
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
