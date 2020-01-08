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
    vector<int> operand;
    vector<char> operato;
    int n;
    vector<int> dfs(int l, int r){
        if (l == r) return vector<int>{operand[l]};
        vector<int> ans;
        for (int i = l; i < r; ++i){
            vector<int> lres = dfs(l, i), rres = dfs(i + 1, r);
            if (operato[i] == '+'){
                for (int ll: lres)
                    for (int rr: rres)
                        ans.push_back(ll + rr);
            }else if (operato[i] == '-'){
                for (int ll: lres)
                    for (int rr: rres)
                        ans.push_back(ll - rr);
            }else if (operato[i] == '*'){
                for (int ll: lres)
                    for (int rr: rres)
                        ans.push_back(ll * rr);
            }else if (operato[i] == '/'){
                for (int ll: lres)
                    for (int rr: rres)
                        if (rr != 0) ans.push_back(ll / rr);
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string input) {
        n = 0;
        for (int i = 0; i < input.size(); ){
            int j = i, x = 0; 
            while (j < input.size() && isdigit(input[j]))
                x = x * 10 + input[j] - '0', ++j;
            operand.push_back(x);
            if (j < input.size()) operato.push_back(input[j]), ++j;
            i = j, ++n;
        }
        return dfs(0, n - 1);
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
