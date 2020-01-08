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
    unordered_map<string, int> mp;
    vector<int> fa;
    int Find(int x){
        return (fa[x] == x ? x: (fa[x] = Find(fa[x])));
    }
    void Union(int x, int y){
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return ;
        fa[fx] = fy;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        fa = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) fa[i] = i;
        for (int i = 0; i < n; ++i){
            int t = accounts[i].size();
            for (int j = 1; j < t; ++j){
                if (!mp.count(accounts[i][j])) mp[accounts[i][j]] = i;
                else Union(i, mp[accounts[i][j]]);
            }
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i){
            Find(i);
            if (fa[i] == i) continue;
            int t = accounts[i].size();
            for (int j = 1; j < t; ++j){
                if (mp.count(accounts[i][j])) 
                    accounts[fa[i]].push_back(accounts[i][j]), 
                    mp.erase(accounts[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) 
            if (fa[i] == i) {
                sort(accounts[i].begin() + 1, accounts[i].end());
                int new_size =
                unique(accounts[i].begin() + 1, accounts[i].end()) - accounts[i].begin();
                int t = accounts[i].size();
                while (t > new_size) 
                    accounts[i].pop_back(), --t;
                ans.push_back(accounts[i]);
            }
                
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
