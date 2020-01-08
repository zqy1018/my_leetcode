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

class Solution {
public:
    bool dfs(string& s1, string& s2, int l1, int r1, int l2, int r2, bool flag){
        if (r1 - l1 == 1)
            return s1[l1] == s2[l2];
        int vec[26] = {0}, cnt = 0;
        for (int i = 1; i < r1 - l1; ++i){
            if (vec[s1[l1 + i - 1]] == 0) ++cnt;
            else if (vec[s1[l1 + i - 1]] == -1) --cnt;
            ++vec[s1[l1 + i - 1]];
            if (flag) {
                if (vec[s2[l2 + i - 1]] == 1) --cnt;
                else if (vec[s2[l2 + i - 1]] == 0) ++cnt;
                --vec[s2[l2 + i - 1]];
                if (cnt == 0 && (dfs(s1, s2, l1, l1 + i, l2, l2 + i, true) || dfs(s1, s2, l1, l1 + i, l2, l2 + i, false)) &&
                    (dfs(s1, s2, l1 + i, r1, l2 + i, r2, true) || dfs(s1, s2, l1 + i, r1, l2 + i, r2, false)))
                    return true;
            }else {
                if (vec[s2[r2 - i]] == 1) --cnt;
                else if (vec[s2[r2 - i]] == 0) ++cnt;
                --vec[s2[r2 - i]];
                if (cnt == 0 && (dfs(s1, s2, l1, l1 + i, r2 - i, r2, true) || dfs(s1, s2, l1, l1 + i, r2 - i, r2, false)) &&
                    (dfs(s1, s2, l1 + i, r1, l2, r2 - i, true) || dfs(s1, s2, l1 + i, r1, l2, r2 - i, false)))
                    return true;
            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        for (int i = 0; i < s1.length(); ++i)
            s1[i] -= 'a';
        for (int i = 0; i < s2.length(); ++i)
            s2[i] -= 'a';
        return dfs(s1, s2, 0, s1.length(), 0, s2.length(), true) || 
            dfs(s1, s2, 0, s1.length(), 0, s2.length(), false);
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
