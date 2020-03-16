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

class Solution {
public:
    int n, dis[5005], l, mindis;
    bool vis[5005];
    int tour[5005], tot;
    vector<vector<string>> ans;
    vector<int> to[5005];
    string st;
    bool ok(string& sa, string& sb){
        int cnt = 0;
        for (int i = 0; i < l; ++i) 
            if (sa[i] != sb[i])
                ++cnt;
        return cnt == 1;
    }
    void dfs(int cur, vector<string>& wordList){
        if (cur == n){
            ans.push_back(vector<string>());
            ans.back().push_back(st);
            for (int i = 1; i < tot; ++i)
                ans.back().push_back(wordList[tour[i] - 1]);
            ans.back().push_back(wordList[n - 1]);
            return ;
        }
        if (dis[cur] == mindis) return ;
        tour[tot++] = cur;
        int tt = to[cur].size();
        
        for (int i: to[cur])
            if (!vis[i])
                vis[i] = true, dfs(i, wordList), vis[i] = false; 
        --tot;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size(), l = beginWord.length();
        st = beginWord;
        for (int i = 0; i < n - 1; ++i)
            if (endWord == wordList[i]){
                swap(wordList[i], wordList[n - 1]);
                break;
            }
        if (wordList[n - 1] != endWord) return ans;
        queue<int> que;
        memset(dis, 0x3f, sizeof(dis));
        dis[0] = 0;
        for (int i = 0; i < n; ++i)
            if (ok(beginWord, wordList[i]))
                dis[i + 1] = 1, que.push(i + 1), to[0].push_back(i + 1);
        while (!que.empty()){
            int h = que.front();
            que.pop();
            for (int i = 1; i <= n; ++i){
                if (dis[i] < dis[h] + 1 || !ok(wordList[h - 1], wordList[i - 1]))
                    continue;
                if (dis[i] > dis[h] + 1) 
                    dis[i] = dis[h] + 1, que.push(i);
                to[h].push_back(i);
            }
        }
        if (dis[n] == 0x3f3f3f3f)
            return ans;
        vis[0] = true, tot = 0, mindis = dis[n];
        dfs(0, wordList);
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
