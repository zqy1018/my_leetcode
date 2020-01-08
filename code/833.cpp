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
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size(), l = S.length();
        vector<int> vec(n, 0);
        for (int i = 0; i < n; ++i) vec[i] = i;
        sort(vec.begin(), vec.end(), [&indexes](int x, int y){ return indexes[x] < indexes[y]; });
        string ans("");
        int cur = 0;
        for (int i = 0; i < n; ++i){
            int id = vec[i];
            while (cur < indexes[id]) ans.push_back(S[cur]), ++cur;
            int j;
            for (j = 0; j < sources[id].length() && cur + j < l; ++j)
                if (S[cur + j] != sources[id][j]) break;
            if (j == sources[id].length())
                ans += targets[id], cur += sources[id].length();
        }
        while (cur < l) ans.push_back(S[cur]), ++cur;
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
