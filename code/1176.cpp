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
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = words.size(), m = puzzles.size();
        for (int i = 0; i < n; ++i){
            int vec = 0, cnt = 0;
            for (char c: words[i]){
                int t = 1 << (c - 'a');
                if (!(vec & t)) vec |= t, ++cnt;
            }
            if (cnt > 7) continue;
            if (mp.count(vec)) mp[vec] = 1;
            else ++mp[vec];
        }
        for (int i = 0; i < m; ++i){
            int cnt = 0;
            int v0 = 1 << (puzzles[i][0] - 'a'),
                v1 = 1 << (puzzles[i][1] - 'a'), 
                v2 = 1 << (puzzles[i][2] - 'a'), 
                v3 = 1 << (puzzles[i][3] - 'a'), 
                v4 = 1 << (puzzles[i][4] - 'a'), 
                v5 = 1 << (puzzles[i][5] - 'a'), 
                v6 = 1 << (puzzles[i][6] - 'a');
            for (int A = 0; A <= v1; A += v1)
            for (int B = 0; B <= v2; B += v2)
            for (int C = 0; C <= v3; C += v3)
            for (int D = 0; D <= v4; D += v4)
            for (int E = 0; E <= v5; E += v5)
            for (int F = 0; F <= v6; F += v6){
                int vec = v0 + A + B + C + D + E + F;
                if (mp.count(vec)) 
                    cnt += mp[vec];
            }
            ans.push_back(cnt);
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
