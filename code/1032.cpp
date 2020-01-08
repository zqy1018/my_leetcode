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

int trie[400005][27], cnt;
bool ok[400005];
class StreamChecker {
public:
    vector<char> vec;
    StreamChecker(vector<string>& words) {
        memset(trie, 0, sizeof(trie));
        memset(ok, 0, sizeof(ok));
        cnt = 1;
        for (string& s: words){
            int l = s.length(), p = 1;
            for (int i = l - 1; i >= 0; --i){
                if (!trie[p][s[i] - 'a'])   
                    trie[p][s[i] - 'a'] = ++cnt;
                p = trie[p][s[i] - 'a'];
            }
            ok[p] = true;
        }
    }
    
    bool query(char letter) {
        vec.push_back(letter);
        int p = 1, cur = vec.size() - 1;
        while (p && cur >= 0 && !ok[p])
            p = trie[p][vec[cur] - 'a'], --cur;
        return p && ok[p];
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
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
