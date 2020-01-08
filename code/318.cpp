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
    int maxProduct(vector<string>& words) {
        vector<int> vec;
        for (int i = 0; i < words.size(); ++i){
            int sum = 0;
            for (char c: words[i])
                sum |= (1 << (c - 'a'));
            vec.push_back(sum);
        }
        int ans = 0;
        for (int i = 1; i < words.size(); ++i){
            for (int j = 0; j < i; ++j){
                if (vec[i] & vec[j]) continue;
                int res = words[i].length() * words[j].length();
                ans = max(ans, res);
            }
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
